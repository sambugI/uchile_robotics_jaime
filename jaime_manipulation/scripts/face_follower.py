#!/usr/bin/env python3

import asyncio

import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Point
from std_msgs.msg import Bool, Float64MultiArray

from rclpy.action import ActionServer

from jaime_interfaces.action import FindFace


class FaceFollower(Node):

    def __init__(self):

        super().__init__("face_follower")


        #################################################
        # Estado de la cara
        #################################################

        self.face_detected = False

        self.error_x = 0.0
        self.error_y = 0.0


        #################################################
        # Control de activación
        #################################################

        self.tracking_enabled = False


        #################################################
        # Parámetros PD
        #################################################

        self.prev_error_x = 0.0
        self.prev_error_y = 0.0

        self.last_time = self.get_clock().now()


        self.kp_yaw = 1.5
        self.kd_yaw = 0.15

        self.kp_pitch = 1.5
        self.kd_pitch = 0.15


        #################################################
        # Suscripciones
        #################################################

        self.face_position_sub = self.create_subscription(
            Point,
            "/face_position",
            self.face_position_callback,
            10
        )


        self.face_detected_sub = self.create_subscription(
            Bool,
            "/face_detected",
            self.face_detected_callback,
            10
        )


        #################################################
        # Publicación velocidades cuello
        #################################################

        self.cmd_pub = self.create_publisher(
            Float64MultiArray,
            "/cmd",
            10
        )


        #################################################
        # Timer controlador
        #################################################

        self.control_timer = self.create_timer(
            0.03,
            self.control_loop
        )


        #################################################
        # Action Server
        #################################################

        self.find_face_action = ActionServer(
            self,
            FindFace,
            "/perception/find_face",
            self.find_face_callback
        )


        self.get_logger().info(
            "Face follower ready"
        )



    #################################################
    # Recepción posición cara
    #################################################

    def face_position_callback(self, msg):

        self.error_x = msg.x
        self.error_y = msg.y



    #################################################
    # Recepción detección
    #################################################

    def face_detected_callback(self, msg):

        self.face_detected = msg.data



    #################################################
    # Loop principal controlador
    #################################################

    def control_loop(self):

        if not self.tracking_enabled:
            return


        if not self.face_detected:

            self.publish_stop()

            return


        self.compute_pd_control()



    #################################################
    # Control PD
    #################################################

    def compute_pd_control(self):

        now = self.get_clock().now()


        dt = (
            now - self.last_time
        ).nanoseconds / 1e9


        if dt <= 0:
            return


        self.last_time = now


        dx = (
            self.error_x -
            self.prev_error_x
        ) / dt


        dy = (
            self.error_y -
            self.prev_error_y
        ) / dt


        self.prev_error_x = self.error_x
        self.prev_error_y = self.error_y


        # Control PD en coordenadas de imagen

        control_x = (
            self.kp_yaw * self.error_x
            +
            self.kd_yaw * dx
        )


        control_y = (
            self.kp_pitch * self.error_y
            +
            self.kd_pitch * dy
        )


        # Saturación

        control_x = max(
            min(control_x, 1.0),
            -1.0
        )


        control_y = max(
            min(control_y, 1.0),
            -1.0
        )


        msg = Float64MultiArray()

        msg.data = [
            float(control_x),
            float(control_y),
            0.0
        ]


        self.cmd_pub.publish(msg)


    #################################################
    # Detener cuello
    #################################################

    def publish_stop(self):

        msg = Float64MultiArray()

        msg.data = [
            0.0,
            0.0,
            0.0
        ]

        self.cmd_pub.publish(msg)


    #################################################
    # Action Server FindFace
    #################################################

    async def find_face_callback(
        self,
        goal_handle
    ):


        self.get_logger().info(
            "FindFace goal received"
        )


        self.tracking_enabled = True


        tolerance = (
            goal_handle.request.tolerance
        )


        while rclpy.ok():


            feedback = FindFace.Feedback()


            feedback.detected = (
                self.face_detected
            )


            feedback.error_x = (
                float(self.error_x)
            )


            feedback.error_y = (
                float(self.error_y)
            )


            goal_handle.publish_feedback(
                feedback
            )



            if (
                self.face_detected
                and
                abs(self.error_x) < tolerance
                and
                abs(self.error_y) < tolerance
            ):

                break



            await asyncio.sleep(0.03)



        self.publish_stop()


        self.tracking_enabled = False



        goal_handle.succeed()


        result = FindFace.Result()

        result.success = True

        result.message = (
            "Face aligned"
        )


        self.get_logger().info(
            "Face aligned successfully"
        )


        return result



    #################################################
    # Shutdown
    #################################################

    def destroy_node(self):

        self.find_face_action.destroy()

        self.publish_stop()

        super().destroy_node()



def main():

    rclpy.init()


    node = FaceFollower()


    try:

        rclpy.spin(node)


    except KeyboardInterrupt:

        pass


    finally:

        node.destroy_node()

        rclpy.shutdown()



if __name__ == "__main__":

    main()