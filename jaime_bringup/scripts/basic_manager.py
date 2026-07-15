#!/usr/bin/env python3

import rclpy

from rclpy.node import Node

from nav_msgs.msg import Odometry
from sensor_msgs.msg import LaserScan

from jaime_interfaces.srv import IsReady


class BasicManager(Node):

    def __init__(self):

        super().__init__("basic_manager")


        self.received_odom = False
        self.received_scan = False


        self.create_subscription(
            Odometry,
            "/odom",
            self.odom_callback,
            10
        )


        self.create_subscription(
            LaserScan,
            "/scan_raw",
            self.scan_callback,
            10
        )


        self.ready_service = self.create_service(
            IsReady,
            "/basic/is_ready",
            self.ready_callback
        )


        self.get_logger().info(
            "Basic manager started"
        )


    def odom_callback(self,msg):

        self.received_odom = True



    def scan_callback(self,msg):

        self.received_scan = True



    def ready_callback(self,request,response):


        if not self.received_odom:

            response.ready=False
            response.message="Waiting for odometry"

            return response



        if not self.received_scan:

            response.ready=False
            response.message="Waiting for lidar"

            return response



        response.ready=True
        response.message="Basic system ready"

        return response
def main(args=None):

    rclpy.init(args=args)

    node = BasicManager()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()
