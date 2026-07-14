#!/usr/bin/env python3

import rclpy

from rclpy.node import Node

from jaime_interfaces.srv import IsReady


class PerceptionManager(Node):

    def __init__(self):

        super().__init__("perception_manager")

        self.ready_service = self.create_service(
            IsReady,
            "/perception/is_ready",
            self.is_ready_callback
        )

        self.get_logger().info(
            "Perception Manager Ready"
        )

    ########################################################

    def node_exists(self, name):

        for node_name, _ in self.get_node_names_and_namespaces():

            if node_name == name:

                return True

        return False

    ########################################################

    def topic_exists(self, topic_name):

        topics = self.get_topic_names_and_types()

        for topic, _ in topics:

            if topic == topic_name:

                return True

        return False

    ########################################################

    def is_ready_callback(self, request, response):

        ##############################################
        # Nodes
        ##############################################

        if not self.node_exists("face_detector"):

            response.ready = False
            response.message = "face_detector node not found"

            return response

        if not self.node_exists("face_tracker"):

            response.ready = False
            response.message = "face_tracker node not found"

            return response

        ##############################################
        # Topics
        ##############################################

        required_topics = [

            "/image_raw",

            "/face_position",

            "/face_detected",

            "/cmd"

        ]

        for topic in required_topics:

            if not self.topic_exists(topic):

                response.ready = False

                response.message = (
                    f"Missing topic: {topic}"
                )

                return response

        ##############################################

        response.ready = True

        response.message = (
            "Perception ready"
        )

        return response


############################################################


def main(args=None):

    rclpy.init(args=args)

    node = PerceptionManager()

    rclpy.spin(node)

    node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()