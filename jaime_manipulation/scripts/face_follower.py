#!/usr/bin/env python3

import cv2

import rclpy
from rclpy.node import Node

from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from std_msgs.msg import Bool

from cv_bridge import CvBridge
from rclpy.action import ActionServer
from jaime_interfaces.action import FindFace


class FaceDetector(Node):

    def __init__(self):

        super().__init__("face_detector")

        self.bridge = CvBridge()

        self.detector = cv2.CascadeClassifier(
            cv2.data.haarcascades +
            "haarcascade_frontalface_default.xml"
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
        self.find_face_action = ActionServer(
            self,
            FindFace,
            "/perception/find_face",
            self.find_face_callback
        )

        self.get_logger().info("Face detector ready.")

    def image_callback(self, msg):

        image = self.bridge.imgmsg_to_cv2(
            msg,
            desired_encoding="bgr8"
        )

        gray = cv2.cvtColor(
            image,
            cv2.COLOR_BGR2GRAY
        )

        faces = self.detector.detectMultiScale(
            gray,
            scaleFactor=1.2,
            minNeighbors=5,
            minSize=(50, 50)
        )

        if len(faces) == 0:

            self.detected_pub.publish(Bool(data=False))
            return

        x, y, w, h = max(
            faces,
            key=lambda f: f[2] * f[3]
        )

        image_h, image_w = image.shape[:2]

        cx = x + w / 2
        cy = y + h / 2

        error_x = (cx - image_w / 2) / (image_w / 2)
        error_y = (cy - image_h / 2) / (image_h / 2)

        size = w / image_w

        pose = Point()
        pose.x = float(error_x)
        pose.y = float(error_y)
        pose.z = float(size)

        self.face_pub.publish(pose)
        self.detected_pub.publish(Bool(data=True))
        
    async def find_face_callback(self, goal_handle):

        self.tracking_enabled = True

        tolerance = goal_handle.request.tolerance

        while rclpy.ok():

            feedback = FindFace.Feedback()

            feedback.detected = self.face_detected
            feedback.error_x = self.error_x
            feedback.error_y = self.error_y

            goal_handle.publish_feedback(feedback)

            if (
                self.face_detected and
                abs(self.error_x) < tolerance and
                abs(self.error_y) < tolerance
            ):
                break

            await asyncio.sleep(0.03)

        self.publish_stop()

        goal_handle.succeed()

        result = FindFace.Result()

        result.success = True
        result.message = "Face aligned"

        return result

def main():

    rclpy.init()

    node = FaceDetector()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()