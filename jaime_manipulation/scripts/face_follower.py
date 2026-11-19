#!/usr/bin/env python3

import asyncio

import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Point, Twist
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

        self.tracking_enabled = True

        #################################################
        # Parámetros PD - Cuello (Pitch)
        #################################################

        self.prev_error_y = 0.0

        self.last_pitch_time = self.get_clock().now()

        self.kp_pitch = 1.5
        self.kd_pitch = 0.15

        #################################################
        # Parámetros PID - Base (Yaw)
        #################################################

        self.prev_error_x = 0.0
        self.integral_x = 0.0

        self.last_yaw_time = self.get_clock().now()

        # Ganancias PID
        self.kp_yaw = 0.8
        self.ki_yaw = 0.05
        self.kd_yaw = 0.03

        # Saturación velocidad angular
        self.max_yaw_velocity = 0.5

        # Límite integral (anti-windup)
        self.max_integral_x = 1.0

        # Velocidad lineal durante el giro
        self.linear_x_turn = -0.08418771624565125

        # Umbral para considerar que no hay giro
        self.min_yaw_velocity = 0.001

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
        # Publicación velocidades base
        #################################################

        self.cmd_vel_pub = self.create_publisher(
            Twist,
            "/cmd_vel_joy",
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
            "Face follower ready - PID Yaw + PD Pitch"
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

            self.publish_stop()
            return

        if not self.face_detected:

            self.publish_stop()
            self.reset_yaw_pid()

            return

        # Control del cuello
        self.compute_pd_control()

        # Control de rotación de la base
        self.compute_pid_yaw()

    #################################################
    # PID de rotación de la base (Yaw)
    #################################################

    def compute_pid_yaw(self):

        now = self.get_clock().now()

        dt = (
            now - self.last_yaw_time
        ).nanoseconds / 1e9

        if dt <= 0:
            return

        self.last_yaw_time = now

        #################################################
        # Error horizontal
        #################################################

        error_x = self.error_x

        #################################################
        # Término proporcional
        #################################################

        proportional = self.kp_yaw * error_x

        #################################################
        # Término integral
        #################################################

        self.integral_x += error_x * dt

        # Anti-windup
        self.integral_x = max(
            min(self.integral_x, self.max_integral_x),
            -self.max_integral_x
        )

        integral = self.ki_yaw * self.integral_x

        #################################################
        # Término derivativo
        #################################################

        derivative_x = (
            error_x - self.prev_error_x
        ) / dt

        self.prev_error_x = error_x

        derivative = self.kd_yaw * derivative_x

        #################################################
        # Control PID
        #################################################

        control_yaw = -(
            proportional
            + integral
            + derivative
        )

        #################################################
        # Saturación
        #################################################

        control_yaw = max(
            min(control_yaw, self.max_yaw_velocity),
            -self.max_yaw_velocity
        )

        #################################################
        # Publicación cmd_vel_joy
        #################################################

        msg = Twist()

        # Solo desplazamiento lineal durante el giro
        if abs(control_yaw) > self.min_yaw_velocity:

            msg.linear.x = 0.0

            msg.angular.z = float(control_yaw)

        else:

            msg.linear.x = 0.0
            msg.angular.z = 0.0

        self.cmd_vel_pub.publish(msg)

        self.get_logger().info(
            f"Yaw PID | Error X: {error_x:.4f} | "
            f"Angular Z: {control_yaw:.4f}"
        )

    #################################################
    # Reiniciar PID de yaw
    #################################################

    def reset_yaw_pid(self):

        self.integral_x = 0.0
        self.prev_error_x = self.error_x

        self.last_yaw_time = self.get_clock().now()

    #################################################
    # PD del cuello (Pitch)
    #################################################

    def compute_pd_control(self):

        now = self.get_clock().now()

        dt = (
            now - self.last_pitch_time
        ).nanoseconds / 1e9

        if dt <= 0:
            return

        self.last_pitch_time = now

        dy = (
            self.error_y - self.prev_error_y
        ) / dt

        self.prev_error_y = self.error_y

        # Control PD
        control_y = (
            self.kp_pitch * self.error_y
            +
            self.kd_pitch * dy
        )

        # Saturación
        control_y = max(
            min(control_y, 0.5),
            -0.5
        )

        msg = Float64MultiArray()

        msg.data = [
            0.0,
            0.0,
            -float(control_y) / 3
        ]

        self.cmd_pub.publish(msg)

    #################################################
    # Detener cuello y base
    #################################################

    def publish_stop(self):

        # Detener cuello
        neck_msg = Float64MultiArray()

        neck_msg.data = [
            0.0,
            0.0,
            0.0
        ]

        self.cmd_pub.publish(neck_msg)

        # Detener base
        base_msg = Twist()

        base_msg.linear.x = 0.0
        base_msg.angular.z = 0.0

        self.cmd_vel_pub.publish(base_msg)

    #################################################
    # Action Server FindFace
    #################################################

    async def find_face_callback(self, goal_handle):

        self.get_logger().info(
            "FindFace goal received"
        )

        self.tracking_enabled = True

        self.prev_error_y = self.error_y
        self.last_pitch_time = self.get_clock().now()

        self.reset_yaw_pid()

        tolerance = goal_handle.request.tolerance

        while rclpy.ok():

            feedback = FindFace.Feedback()

            feedback.detected = self.face_detected

            feedback.error_x = float(self.error_x)
            feedback.error_y = float(self.error_y)

            goal_handle.publish_feedback(feedback)

            if (
                self.face_detected
                and abs(self.error_y) < tolerance
                and abs(self.error_x) < tolerance
            ):

                break

            await asyncio.sleep(0.03)

        self.publish_stop()

        self.reset_yaw_pid()

        self.tracking_enabled = False

        goal_handle.succeed()

        result = FindFace.Result()

        result.success = True
        result.message = "Face aligned"

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