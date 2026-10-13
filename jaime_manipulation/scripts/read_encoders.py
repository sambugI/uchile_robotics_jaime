#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node

from std_msgs.msg import Float64MultiArray, Bool

import serial
import time
import re


class EncoderHandler:

    def __init__(
        self,
        port='/dev/head_ino',
        baudrate=115200,
        timeout=0.001
    ):

        self.ser = serial.Serial(
            port,
            baudrate,
            timeout=timeout
        )

        time.sleep(2)

        self.ser.reset_input_buffer()

        print(f"Puerto serial {port} abierto a {baudrate} baudios.")

    def get_angles(self):
        latest = None

        try:
            while self.ser.in_waiting > 0:
                raw = self.ser.readline()

                if not raw:
                    continue

                decoded = raw.decode("utf-8", errors="ignore").strip()

                if not decoded:
                    continue

                if "Reading from" in decoded:
                    continue

                values = re.findall(r'-?\d+\.?\d*', decoded)
                if len(values) != 5:
                    continue

                latest = [float(v) for v in values]

            return latest

        except Exception as e:
            print("Serial parse error:", e)
            return None

    def close(self):

        if self.ser.is_open:
            self.ser.close()


class EncoderNode(Node):

    def __init__(self):

        super().__init__('encoder_node')

        # Publicador de los 4 encoders
        self.encoder_pub = self.create_publisher(
            Float64MultiArray,
            'encoder_angles',
            10
        )

        # Publicador del botón de emergencia
        self.emergency_pub = self.create_publisher(
            Bool,
            'emergency_button',
            10
        )

        self.encoder = EncoderHandler()

        self.timer = self.create_timer(
            0.05,
            self.publish_angles
        )

    def publish_angles(self):

        values = self.encoder.get_angles()
        if values is None:
            return

        # Publicar los primeros 4 valores en encoder_angles
        msg = Float64MultiArray()
        msg.data = values[:4]

        self.encoder_pub.publish(msg)

        # Publicar el quinto valor en emergency_button
        emergency_msg = Bool()
        # Se publica en el script de emergencia si el valor es -1.0, indicando que se ha presionado el botón de emergencia
        emergency_msg.data = (values[4] == -1.0)

        self.emergency_pub.publish(emergency_msg)

    def destroy_node(self):

        try:
            self.encoder.close()

        except Exception as e:
            print(f"Error cerrando serial: {e}")

        super().destroy_node()


def main(args=None):

    rclpy.init(args=args)

    node = EncoderNode()

    try:
        rclpy.spin(node)

    except KeyboardInterrupt:
        pass

    finally:
        node.destroy_node()

        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()