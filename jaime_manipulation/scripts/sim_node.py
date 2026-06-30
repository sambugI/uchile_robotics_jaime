#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Header
from dynamixel_sdk import *  
from std_msgs.msg import Float64MultiArray
from dynamixel_node import DynamixelCommander
import math 
import numpy as np

class DynamixelJointPublisher(Node):
    def __init__(self):
        super().__init__('dynamixel_joint_publisher')

        # Crear publicador
        self.joint_pub = self.create_subscription(JointState, 'joint_states',self.joints_states_node, 10)

        self.pub = self.create_publisher(Float64MultiArray, '/velocity_controller/commands', 10)

        self.move_timer = self.create_timer(0.01, self.move_joints)  

        # Subscriptor a velocidad deseada
        self.velocitie_sub = self.create_subscription(
            Float64MultiArray,
            'goal_vel',
            self.velocitie_callback,
            10
        )

        self.joints = [0,0,0,0,0]
        self.vel = [0,0,0,0,0]

        self.lower_limits = [0,0,0,0,-3]
        self.upper_limits = [0.38,0.38,0.69,0.69,3]
        
   
    def joints_states_node(self,msg: JointState):
        angulos = msg.position.tolist()
        self.joints = angulos

        
    def move_joints(self):
        for i in range(len(self.vel)):
            if (self.vel[i] < 0 and self.lower_limits[i] >= self.joints[i]):
                print(i, "limite alcanzado")
                self.vel[i] = 0
            elif (self.vel[i] > 0 and self.upper_limits[i] <= self.joints[i]):
                print(i, "limite alcanzado")
                self.vel[i] = 0

        msg = Float64MultiArray()
        msg.data = [self.vel[0],self.vel[0],self.vel[1],self.vel[1],self.vel[2]]
        self.pub.publish(msg)
        
    def velocitie_callback(self, msg: Float64MultiArray):
        if len(msg.data) != 3:
            self.get_logger().warn("Se esperaban exactamente 3 posiciones (en radianes)")
            return
        
        else:
            self.vel = np.clip(msg.data, -0.5, 0.5).tolist()

    def destroy_node(self):
        pass


def main(args=None):
    rclpy.init(args=args)
    node = DynamixelJointPublisher()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


main()