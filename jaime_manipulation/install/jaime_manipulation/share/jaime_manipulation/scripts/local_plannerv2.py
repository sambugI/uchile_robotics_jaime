#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from std_msgs.msg import Float64MultiArray
from sensor_msgs.msg import JointState
from geometry_msgs.msg import PoseStamped

from utils import jaime_solution

import numpy as np


class LocalPlanner(Node):

    def __init__(self):

        super().__init__('local_planner_v2')

        self._fk_publisher = self.create_publisher(
            PoseStamped,
            'eef_pose',
            1)

        self.pub = self.create_publisher(
            Float64MultiArray,
            'goal_vel',
            10)

        # Subs
        self._joint_state_sub = self.create_subscription(
            JointState,
            '/joint_states',
            self._joint_states_callback,
            1)

        self._cmd_sub = self.create_subscription(
            Float64MultiArray,
            '/cmd',
            self.cmd_callback,
            1)

        self._goal_pos_sub = self.create_subscription(
            Float64MultiArray,
            '/goal_pos',
            self.goal_pos_callback,
            1)

        # Timer
        self.update = self.create_timer(
            0.05,
            self.update_velocity)

        self.jaime = jaime_solution()

        self._joint_states = [0, 0, 0, 0, 0]

        # Modes
        # 0 -> velocity cmd
        # 1 -> position target
        self.state = 0

        self.cmd = None

        self.goal_pos = None

        self.goal_velocity = np.zeros(3)

        # Gains
        self.Kp = 2.0

        # Limits
        self.max_joint_vel = 2.0

        # Damping
        self.damping = 0.05

        # Position tolerance
        self.pos_tolerance = 0.01

    def _joint_states_callback(self, msg):

        self._joint_states = msg.position.tolist()

        self.jaime.update(self._joint_states)

        self.pub_pose()

    def cmd_callback(self, msg):

        self.state = 0

        self.cmd = np.array(msg.data.tolist(), dtype=float)

    def goal_pos_callback(self, msg):

        self.state = 1

        self.goal_pos = np.array(
            msg.data.tolist(),
            dtype=float)

    def update_velocity(self):

        # ----------------------------------
        # MODE 0: DIRECT CARTESIAN VELOCITY
        # ----------------------------------

        if self.state == 0:

            if self.cmd is not None:

                vel = self.jaime.compute_damped_pos_velocity(
                    self.cmd,
                    damping=self.damping)

                vel = np.clip(
                    vel,
                    -self.max_joint_vel,
                    self.max_joint_vel)

                self.goal_velocity = vel

        # ----------------------------------
        # MODE 1: CARTESIAN SERVOING
        # ----------------------------------

        else:

            if self.goal_pos is not None:

                current_pos = np.array(
                    self.jaime.position,
                    dtype=float)

                pos_error = self.goal_pos - current_pos

                error_norm = np.linalg.norm(pos_error)

                # Goal reached
                if error_norm < self.pos_tolerance:

                    self.goal_velocity = np.zeros(3)

                else:

                    # Cartesian proportional controller
                    cartesian_cmd = self.Kp * pos_error

                    vel = self.jaime.compute_damped_pos_velocity(
                        cartesian_cmd,
                        damping=self.damping)

                    vel = np.clip(
                        vel,
                        -self.max_joint_vel,
                        self.max_joint_vel)

                    self.goal_velocity = vel

        msg = Float64MultiArray()

        msg.data = self.goal_velocity.tolist()

        self.pub.publish(msg)

    def pub_pose(self):

        if self._joint_states is None:
            return

        eef_position, eef_quaternion, euler = self.jaime.get_pose()

        eef_pose = PoseStamped()

        eef_pose.header.stamp = self.get_clock().now().to_msg()

        eef_pose.header.frame_id = "base_link"

        eef_pose.pose.position.x = eef_position[0]
        eef_pose.pose.position.y = eef_position[1]
        eef_pose.pose.position.z = eef_position[2]

        eef_pose.pose.orientation.x = eef_quaternion[0]
        eef_pose.pose.orientation.y = eef_quaternion[1]
        eef_pose.pose.orientation.z = eef_quaternion[2]
        eef_pose.pose.orientation.w = eef_quaternion[3]

        self._fk_publisher.publish(eef_pose)


def main(args=None):

    rclpy.init(args=args)

    lp = LocalPlanner()

    rclpy.spin(lp)

    lp.destroy_node()

    rclpy.shutdown()


if __name__ == '__main__':
    main()
