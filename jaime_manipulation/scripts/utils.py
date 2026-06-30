#!/usr/bin/env python3
import numpy as np
from fk_solution import fk_solution
import tf_transformations as tf


def wrap_to_range(angle, min_val, max_val):
    """
    Envuelve (wrap) un ángulo al rango [min_val, max_val).
    """
    return (angle - min_val) % (max_val - min_val) + min_val

def wrap_custom_angles(angles):
    a = np.array(angles)

    a1 = wrap_to_range(a[0], 0, np.pi/2)
    a2 = wrap_to_range(a[1], 0, np.pi/2)
    a3 = wrap_to_range(a[2], -np.pi/2, np.pi/2)

    return np.array([a1, a2, a3])

class jaime_solution():
    def __init__(self):
        self.position = None
        self.orientation = None
        self.joints = None
        self._jacobian, self._fk,self._pos_jacobian = fk_solution()
        
    
    def update(self, joints):
        self.joints = [joints[0],joints[2],joints[4]]

        fk = self._fk(*self.joints)  # matriz 4x4 de transformación homogénea

        self.position = fk[:3, 3]
        self.orientation = tf.quaternion_from_matrix(fk)  # [x, y, z, w]
        self.euler = tf.euler_from_matrix(fk[:3, :3])     # (roll, pitch, yaw)

    def get_pose(self):
        return self.position,self.orientation,self.euler

    def compute_ik(self, desired_position, desired_orientation_rpy, max_iters=500, epsilon=1e-3, max_attempts=5):
        q = np.array(self.joints, dtype=float)  
        for attempt in range(max_attempts):
            

            for i in range(max_iters):
                T = self._fk(*q)
                pos = T[:3, 3]
                R = T[:3, :3]

                current_rpy = np.array([
                    np.arctan2(R[2,1], R[2,2]),
                    -np.arcsin(R[2,0]),
                    np.arctan2(R[1,0], R[0,0])
                ])

                pos_error = desired_position - pos
                ori_error = (desired_orientation_rpy - current_rpy + np.pi) % (2 * np.pi) - np.pi
                error = np.concatenate((pos_error, ori_error))
                
                if np.linalg.norm(error) < epsilon:
                    return q
                
                J = self._jacobian(*q)
                delta_q = np.linalg.pinv(J) @ error
                q += delta_q
                q = wrap_custom_angles(q)

            print(f"Intento {attempt+1}/{max_attempts} falló.")
            q = np.random.uniform(-np.pi, np.pi, size=3) 

        print("No se encontró solución después de múltiples intentos.")
        return None
    def compute_ik_position_only(
        self,
        desired_position,
        max_iters=500,
        epsilon=1e-3):

            q = np.array(self.joints, dtype=float)

            for i in range(max_iters):

                T = self._fk(*q)

                pos = T[:3, 3]

                pos_error = desired_position - pos

                if np.linalg.norm(pos_error) < epsilon:
                    return q

                J = self._pos_jacobian(*q)

                delta_q = np.linalg.pinv(J) @ pos_error

                q += delta_q

                q = wrap_custom_angles(q)

            return None
    def compute_damped_pos_velocity(self, cmd, damping=0.1):

            if self.joints is None:
                return np.zeros(3)

            q = np.array(self.joints, dtype=float)

            J = self._pos_jacobian(*q)

            JT = J.T

            lambda_I = (damping ** 2) * np.eye(J.shape[0])

            # Damped Least Squares
            vel = JT @ np.linalg.inv(J @ JT + lambda_I) @ cmd

            return vel
            
    #compute cartesian velocity for pose (x,y,z,r,p,yaw)
    def compute_velocity(self, cmd):
        q = np.array(self.joints, dtype=float) 

        J = self._jacobian(*q)

        vel = np.linalg.pinv(J) @ cmd

        return vel
    
    #compute cartesian velocity only for position (x,y,z)
    def compute_pos_velocity(self, cmd):
        if self.joints:
            q = np.array(self.joints, dtype=float) 

            J = self._pos_jacobian(*q)

            vel = np.linalg.pinv(J) @ cmd

            return vel
        else:
            return [0,0,0]
