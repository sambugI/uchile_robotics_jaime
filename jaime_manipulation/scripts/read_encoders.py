#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node

from std_msgs.msg import Float64MultiArray

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

                    values = re.findall(r'-?\d+\.\d+', decoded)
                    if len(values) != 4:
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

        self.encoder_pub = self.create_publisher(
            Float64MultiArray,
            'encoder_angles',
            10
        )

        self.timer = self.create_timer(
            0.05,
            self.publish_angles
        )

        self.encoder = EncoderHandler()

    def publish_angles(self):

        ang = self.encoder.get_angles()

        if ang is None:
            return
        msg = Float64MultiArray()

        msg.data = ang

        self.encoder_pub.publish(msg)

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