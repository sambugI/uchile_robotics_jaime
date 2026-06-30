#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
import math
import numpy as np

class JointPositionPublisher(Node):
    def __init__(self):
        super().__init__('joint_position_publisher')

        self.pub = self.create_publisher(Float64MultiArray, 'goal_vel', 10)

        # Publica cada 0.1 s (10 Hz)
        self.timer = self.create_timer(0.1, self.publish_positions)


    def publish_positions(self):
        msg = Float64MultiArray()

        # Ejemplo: trayectorias suaves senoidales
        q1 = 0.0
        q2 = 0.0
        q3 = float(input("vel:"))

        msg.data = [q3,q2, q1]

        self.pub.publish(msg)
        self.get_logger().info(f'Enviando posiciones: {msg.data}')


def main(args=None):
    rclpy.init(args=args)
    node = JointPositionPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
