#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

import subprocess

from sensor_msgs.msg import Image
from std_msgs.msg import String

from jaime_interfaces.srv import IsReady



class TabletManager(Node):

    def __init__(self):

        super().__init__("tablet_manager")


        self.camera_ok = False
        self.file_publisher_ok = False
        self.adb_ok = False


        # Imagen de android_cam
        self.image_sub = self.create_subscription(
            Image,
            "/image_raw",
            self.image_callback,
            10
        )


        # Comunicación con file_publisher
        self.path_sub = self.create_subscription(
            String,
            "/path",
            self.path_callback,
            10
        )


        self.ready_srv = self.create_service(
            IsReady,
            "/tablet/is_ready",
            self.ready_callback
        )


        self.timer = self.create_timer(
            2.0,
            self.check_adb
        )


        self.get_logger().info(
            "Tablet manager started"
        )


    # ----------------------------
    # Cámara Android
    # ----------------------------

    def image_callback(self,msg):

        self.camera_ok = True



    # ----------------------------
    # File publisher
    # ----------------------------

    def path_callback(self,msg):

        self.file_publisher_ok = True



    # ----------------------------
    # ADB
    # ----------------------------

    def check_adb(self):

        try:

            result = subprocess.run(
                ["adb","devices"],
                capture_output=True,
                text=True,
                timeout=2
            )


            lines = result.stdout.splitlines()


            for line in lines:

                if "\tdevice" in line:

                    self.adb_ok = True
                    return


            self.adb_ok = False


        except Exception:

            self.adb_ok = False



    # ----------------------------
    # Servicio
    # ----------------------------

    def ready_callback(self,request,response):


        if not self.adb_ok:

            response.ready = False
            response.message = (
                "Tablet not connected through adb"
            )

            return response



        if not self.camera_ok:

            response.ready = False
            response.message = (
                "Waiting for android camera"
            )

            return response



        if not self.file_publisher_ok:

            response.ready = False
            response.message = (
                "Waiting for file publisher"
            )

            return response



        response.ready = True
        response.message = (
            "Tablet ready"
        )

        return response




def main(args=None):

    rclpy.init(args=args)

    node = TabletManager()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()



if __name__ == "__main__":
    main()