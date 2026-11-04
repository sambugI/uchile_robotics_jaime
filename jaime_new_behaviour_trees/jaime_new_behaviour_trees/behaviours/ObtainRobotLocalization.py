```python
import json
from pathlib import Path

import py_trees
import rclpy
import tf2_ros

from geometry_msgs.msg import (
    PoseStamped,
    PoseWithCovarianceStamped
)


class ObtainRobotLocalization(py_trees.behaviour.Behaviour):

    def __init__(self, node):

        super().__init__("ObtainRobotLocalization")

        self.node = node

        self.bb = py_trees.blackboard.Client(
            name="Localization"
        )

        self.bb.register_key(
            key="robot_pose",
            access=py_trees.common.Access.WRITE
        )

        # TF
        self.tf_buffer = tf2_ros.Buffer()

        self.tf_listener = tf2_ros.TransformListener(
            self.tf_buffer,
            node
        )

        # Publicador para inicializar AMCL
        self.initial_pose_pub = self.node.create_publisher(
            PoseWithCovarianceStamped,
            '/initialpose',
            10
        )

        # Ruta de goal_poses.json
        self.config_path = (
            Path(__file__).resolve().parents[1]
            / "goal_poses.json"
        )

        self.initial_pose_sent = False

        self.node.get_logger().info(
            "ObtainRobotLocalization inicializado."
        )

    def publish_initial_pose(self):

        # Cargar configuraciones
        with open(self.config_path, "r") as file:
            poses = json.load(file)

        partida = poses["partida"]

        msg = PoseWithCovarianceStamped()

        msg.header.stamp = (
            self.node.get_clock().now().to_msg()
        )

        msg.header.frame_id = "map"

        # Posición
        msg.pose.pose.position.x = partida["position"]["x"]
        msg.pose.pose.position.y = partida["position"]["y"]
        msg.pose.pose.position.z = partida["position"]["z"]

        # Orientación
        msg.pose.pose.orientation.x = partida["orientation"]["x"]
        msg.pose.pose.orientation.y = partida["orientation"]["y"]
        msg.pose.pose.orientation.z = partida["orientation"]["z"]
        msg.pose.pose.orientation.w = partida["orientation"]["w"]

        # Covarianza inicial
        msg.pose.covariance[0] = 0.25
        msg.pose.covariance[7] = 0.25
        msg.pose.covariance[35] = 0.0685

        self.initial_pose_pub.publish(msg)

        self.initial_pose_sent = True

        self.node.get_logger().info(
            "Posición inicial publicada en /initialpose."
        )

    def update(self):

        # Inicializar AMCL una sola vez
        if not self.initial_pose_sent:

            self.publish_initial_pose()

            return py_trees.common.Status.RUNNING

        # Esperar a que AMCL publique la transformación
        try:

            transform = self.tf_buffer.lookup_transform(
                "map",
                "base_link",
                rclpy.time.Time()
            )

        except Exception:

            self.node.get_logger().warn(
                "Waiting for localization TF"
            )

            return py_trees.common.Status.RUNNING

        # Obtener posición estimada
        pose = PoseStamped()

        pose.header.stamp = (
            self.node.get_clock()
            .now()
            .to_msg()
        )

        pose.header.frame_id = "map"

        pose.pose.position.x = (
            transform.transform.translation.x
        )

        pose.pose.position.y = (
            transform.transform.translation.y
        )

        pose.pose.position.z = (
            transform.transform.translation.z
        )

        pose.pose.orientation = (
            transform.transform.rotation
        )

        self.bb.robot_pose = pose

        self.node.get_logger().info(
            "Localización del robot obtenida correctamente."
        )

        return py_trees.common.Status.SUCCESS
```