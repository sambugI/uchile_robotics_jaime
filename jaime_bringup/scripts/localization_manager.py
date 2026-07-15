#!/usr/bin/env python3

# Verifica si el código de localization manager funciona correctamente.
import rclpy
from rclpy.node import Node

from jaime_interfaces.srv import IsReady

from geometry_msgs.msg import PoseWithCovarianceStamped
from nav_msgs.msg import OccupancyGrid

import tf2_ros


class LocalizationManager(Node):

    def __init__(self):

        super().__init__("localization_manager")


        # -----------------------------
        # Estados del sistema
        # -----------------------------

        self.received_amcl_pose = False
        self.received_map = False


        # -----------------------------
        # Subscribers
        # -----------------------------

        self.amcl_sub = self.create_subscription(
            PoseWithCovarianceStamped,
            "/amcl_pose",
            self.amcl_callback,
            10
        )


        self.map_sub = self.create_subscription(
            OccupancyGrid,
            "/map",
            self.map_callback,
            10
        )


        # -----------------------------
        # TF listener
        # -----------------------------

        self.tf_buffer = tf2_ros.Buffer()

        self.tf_listener = tf2_ros.TransformListener(
            self.tf_buffer,
            self
        )


        # -----------------------------
        # Servicio de estado
        # -----------------------------

        self.ready_service = self.create_service(
            IsReady,
            "/localization/is_ready",
            self.ready_callback
        )


        self.get_logger().info(
            "Localization manager started"
        )


    # --------------------------------------------------
    # Callbacks
    # --------------------------------------------------

    def amcl_callback(self, msg):

        self.received_amcl_pose = True


    def map_callback(self, msg):

        self.received_map = True


    # --------------------------------------------------
    # Service callback
    # --------------------------------------------------

    def ready_callback(self, request, response):

        # 1) Verificar mapa

        if not self.received_map:

            response.ready = False
            response.message = (
                "Waiting for map_server (/map)"
            )

            return response


        # 2) Verificar AMCL

        if not self.received_amcl_pose:

            response.ready = False
            response.message = (
                "Waiting for AMCL pose (/amcl_pose)"
            )

            return response


        # 3) Verificar TF map -> odom

        try:

            self.tf_buffer.lookup_transform(
                "map",
                "odom",
                rclpy.time.Time()
            )


        except Exception as e:

            response.ready = False
            response.message = (
                "Waiting for TF map->odom"
            )

            return response


        response.ready = True
        response.message = (
            "Localization ready"
        )

        return response



def main(args=None):

    rclpy.init(args=args)

    node = LocalizationManager()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()



if __name__ == "__main__":
    main()