#!/usr/bin/env python3
import json
from pathlib import Path

import py_trees

from geometry_msgs.msg import PoseStamped


class ReceiveMission(py_trees.behaviour.Behaviour):

    def __init__(self, node):

        super().__init__("ReceiveMission")

        self.node = node

        # Blackboard
        self.bb = py_trees.blackboard.Client(
            name="MissionWriter"
        )

        self.bb.register_key(
            key="goal_pose",
            access=py_trees.common.Access.WRITE
        )

        # Ruta de goal_poses.json
        self.config_path = (
            Path(__file__).resolve().parents[1]
            / "goal_poses.json"
        )

    def update(self):

        try:

            # Cargar posiciones
            with open(self.config_path, "r") as file:
                poses = json.load(file)

            # Obtener posición de cocina
            cocina = poses["cocina"]

            # Crear PoseStamped
            pose = PoseStamped()

            pose.header.stamp = (
                self.node.get_clock().now().to_msg()
            )

            pose.header.frame_id = "map"

            # Posición
            pose.pose.position.x = cocina["position"]["x"]
            pose.pose.position.y = cocina["position"]["y"]
            pose.pose.position.z = cocina["position"]["z"]

            # Orientación
            pose.pose.orientation.x = cocina["orientation"]["x"]
            pose.pose.orientation.y = cocina["orientation"]["y"]
            pose.pose.orientation.z = cocina["orientation"]["z"]
            pose.pose.orientation.w = cocina["orientation"]["w"]

            # Guardar misión en Blackboard
            self.bb.goal_pose = pose

            self.node.get_logger().info(
                "Mission received successfully: cocina"
            )

            self.node.get_logger().info(
                f"Goal position: "
                f"x={pose.pose.position.x:.3f}, "
                f"y={pose.pose.position.y:.3f}"
            )

            return py_trees.common.Status.SUCCESS

        except Exception as e:

            self.node.get_logger().error(
                f"Error obtaining kitchen position: {e}"
            )

            return py_trees.common.Status.FAILURE
