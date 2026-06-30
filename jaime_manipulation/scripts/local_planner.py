#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray
from geometry_msgs.msg import PoseStamped, Point
import tf_transformations as tf
from utils import jaime_solution
import numpy as np
from scipy.spatial.transform import Rotation as R

class LocalPlanner(Node):
    def __init__(self):
        super().__init__('local_planner')

        self._fk_publisher = self.create_publisher(PoseStamped, 'eef_pose', 1)

        self.pub = self.create_publisher(Float64MultiArray, 'goal_vel', 10)

        # Subscriber for joint states
        self._joint_state_subscription = self.create_subscription(
            JointState,
            '/joint_states',
            self._joint_states_callback,
            1)
        
        self._cmd_sub  = self.create_subscription(
            Float64MultiArray,
            '/cmd',
            self.cmd_callback,
            1)
        
        self._goal_pos_sub  = self.create_subscription(
            Float64MultiArray,
            '/goal_pos',
            self.goal_pos_callback,
            1)
        

        self.update = self.create_timer(0.1, self.update_velocity)


        self._joint_states = [0,0,0,0,0]
        self.jaime = jaime_solution()

        #Current state 0(cmd), 1 (goal_pos)
        self.state = 0
        self.goal_ang = None
        self.goal_velocity = [0,0,0]
        self.cmd = None

    def _joint_states_callback(self, msg):
        
        self._joint_states = msg.position.tolist()
        self.jaime.update(self._joint_states)
        self.pub_pose()

    def cmd_callback(self,msg):
        self.state = 0
        self.cmd = msg.data.tolist()
        
        
    
    def goal_pos_callback(self, msg):
        self.state = 1
        goal_pos = msg.data.tolist()

        #self.goal_ang = self.jaime.compute_ik(goal_pos,[0,0,0])
        self.goal_ang = self.jaime.compute_ik_position_only(goal_pos)

        
    def update_velocity(self):
        if self.state == 0:
            if self.cmd:
                vel = self.jaime.compute_velocity(self.cmd)
 
                # Normalización
                max_val = max(abs(v) for v in vel)  # valor máximo absoluto
                if max_val > 1.0:                   # solo normaliza si es necesario
                    vel = [2*(v / max_val) for v in vel]

                
                self.goal_velocity = [-vel[0],-vel[1],0.08*vel[2]]
                print(self.goal_velocity)
        else:
            if self.goal_ang is not None:
                current_ang = [self._joint_states[0],self._joint_states[2],self._joint_states[4]]
                
                error = np.array(self.goal_ang)-np.array(current_ang)
                
                if np.linalg.norm(error) < 1e-2:
                    self.goal_velocity = [0.0, 0.0, 0.0]
                    return
                vel = 5 * error
                
                max_val = max(abs(v) for v in vel)  # valor máximo absoluto
                if max_val > 1.0:                   # solo normaliza si es necesario
                    vel = [2*(v / max_val) for v in vel]

                self.goal_velocity = vel
        
        
        msg = Float64MultiArray()
        msg.data = self.goal_velocity
        self.pub.publish(msg)


    def pub_pose(self):

        if self._joint_states is None:
            return 

        self.eef_position, self.eef_quaternion,self.euler = self.jaime.get_pose()

        eef_pose = PoseStamped()
        eef_pose.header.stamp = self.get_clock().now().to_msg()
        eef_pose.header.frame_id = "base_link" 

        eef_pose.pose.position.x = self.eef_position[0]
        eef_pose.pose.position.y = self.eef_position[1]
        eef_pose.pose.position.z = self.eef_position[2]

        eef_pose.pose.orientation.x = self.eef_quaternion[0]
        eef_pose.pose.orientation.y = self.eef_quaternion[1]
        eef_pose.pose.orientation.z = self.eef_quaternion[2]
        eef_pose.pose.orientation.w = self.eef_quaternion[3]

        self._fk_publisher.publish(eef_pose)


def main(args=None):
    rclpy.init(args=args)

    lp = LocalPlanner()

    rclpy.spin(lp)

    lp.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
