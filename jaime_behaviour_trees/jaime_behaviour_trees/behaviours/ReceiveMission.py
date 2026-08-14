#!/usr/bin/env python3

import py_trees
import numpy as np

from geometry_msgs.msg import PoseStamped, PointStamped
from tf_transformations import quaternion_from_euler


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

        # Suscripción a RViz /clicked_point
        self.subscription = self.node.create_subscription(
            PointStamped,
            "/clicked_point",
            self.clicked_point_callback,
            10
        )

        self.first_point = None
        self.second_point = None

    def initialise(self):

        self.first_point = None
        self.second_point = None

        self.node.get_logger().info(
            "Waiting for first click..."
        )

    def clicked_point_callback(self, msg):

        point = msg.point

        if self.first_point is None:

            self.first_point = point

            self.node.get_logger().info(
                f"First point received: "
                f"x={point.x:.3f}, y={point.y:.3f}"
            )

        elif self.second_point is None:

            self.second_point = point

            self.node.get_logger().info(
                f"Second point received: "
                f"x={point.x:.3f}, y={point.y:.3f}"
            )

    def update(self):

        # Todavía no llegó el primer click
        if self.first_point is None:

            return py_trees.common.Status.RUNNING

        # Llegó primer click, pero falta segundo
        if self.second_point is None:

            return py_trees.common.Status.RUNNING

        # ------------------------------------------------
        # Calcular orientación
        # ------------------------------------------------

        dx = (
            self.second_point.x -
            self.first_point.x
        )

        dy = (
            self.second_point.y -
            self.first_point.y
        )

        # Evitar clicks prácticamente iguales
        if np.hypot(dx, dy) < 0.01:

            self.node.get_logger().warn(
                "Second click is too close to first click"
            )

            self.second_point = None

            return py_trees.common.Status.RUNNING

        yaw = np.arctan2(dy, dx)

        self.node.get_logger().info(
            f"Mission yaw: {yaw:.3f} rad"
        )

        # ------------------------------------------------
        # Convertir yaw a quaternion
        # ------------------------------------------------

        q = quaternion_from_euler(
            0.0,
            0.0,
            yaw
        )

        # ------------------------------------------------
        # Crear PoseStamped
        # ------------------------------------------------

        pose = PoseStamped()

        pose.header.frame_id = "map"

        pose.pose.position.x = self.first_point.x
        pose.pose.position.y = self.first_point.y
        pose.pose.position.z = 0.0

        pose.pose.orientation.x = q[0]
        pose.pose.orientation.y = q[1]
        pose.pose.orientation.z = q[2]
        pose.pose.orientation.w = q[3]

        # Guardar misión en Blackboard
        self.bb.goal_pose = pose

        self.node.get_logger().info(
            "Mission received successfully"
        )

        return py_trees.common.Status.SUCCESS