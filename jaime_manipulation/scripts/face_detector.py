#!/usr/bin/env python3

import cv2
import os

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from std_msgs.msg import Bool

from cv_bridge import CvBridge


class FaceDetector(Node):

    def __init__(self):

        super().__init__("face_detector")

        self.bridge = CvBridge()

        model_path = os.path.join(
            os.path.dirname(os.path.dirname(os.path.abspath(__file__))),
            "models",
            "face_detection_yunet_2023mar.onnx"
        )

        if not os.path.exists(model_path):
            raise FileNotFoundError(f"No se encontró el modelo YuNet: {model_path}")

        self.detector = cv2.FaceDetectorYN.create(
            model_path,
            "",
            (640, 480),
            score_threshold=0.7,
            nms_threshold=0.3,
            top_k=5000
        )

        self.create_subscription(
            Image,
            "/image_raw",
            self.image_callback,
            10
        )

        self.face_pub = self.create_publisher(
            Point,
            "/face_position",
            10
        )

        self.detected_pub = self.create_publisher(
            Bool,
            "/face_detected",
            10
        )

        self.get_logger().info("Face detector ready.")

    def image_callback(self, msg):

        image = self.bridge.imgmsg_to_cv2(
            msg,
            desired_encoding="bgr8"
        )

        image_h, image_w = image.shape[:2]

        # Actualizar dimensiones de entrada de YuNet
        self.detector.setInputSize((image_w, image_h))

        # Detectar rostros
        _, faces = self.detector.detect(image)

        if faces is None or len(faces) == 0:
            self.detected_pub.publish(Bool(data=False))
            return

        # Seleccionar el rostro de mayor área
        face = max(
            faces,
            key=lambda f: f[2] * f[3]
        )

        x, y, w, h = face[:4].astype(int)

        # Calcular centro del rostro
        cx = x + w / 2
        cy = y + h / 2

        error_x = (cx - image_w / 2) / (image_w / 2)
        error_y = (cy - image_h / 2) / (image_h / 2)

        # Tamaño relativo del rostro
        size = w / image_w

        pose = Point()
        pose.x = float(error_x)
        pose.y = float(error_y)
        pose.z = float(size)

        self.face_pub.publish(pose)
        self.detected_pub.publish(Bool(data=True))

def main():

    rclpy.init()

    node = FaceDetector()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()