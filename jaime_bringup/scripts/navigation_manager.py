#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

from jaime_interfaces.srv import IsReady

from nav2_msgs.action import NavigateToPose
from rclpy.action import ActionClient


class NavigationManager(Node):

    def __init__(self):

        super().__init__("navigation_manager")


        # Cliente hacia Nav2

        self.nav_client = ActionClient(
            self,
            NavigateToPose,
            "/navigate_to_pose"
        )


        # Servicio para Behavior Tree

        self.ready_service = self.create_service(
            IsReady,
            "/navigation/is_ready",
            self.ready_callback
        )


        self.get_logger().info(
            "Navigation manager started"
        )


    def ready_callback(self, request, response):

        available = self.nav_client.wait_for_server(
            timeout_sec=0.1
        )


        if not available:

            response.ready = False
            response.message = (
                "Waiting for Nav2 navigate_to_pose action"
            )

            return response



        response.ready = True
        response.message = (
            "Navigation ready"
        )

        return response



def main(args=None):

    rclpy.init(args=args)

    node = NavigationManager()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()