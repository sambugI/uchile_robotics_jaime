import py_trees
import rclpy
import tf2_ros

from geometry_msgs.msg import PoseStamped


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


        self.tf_buffer = tf2_ros.Buffer()

        self.tf_listener = tf2_ros.TransformListener(
            self.tf_buffer,
            node
        )



    def update(self):

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


        return py_trees.common.Status.SUCCESS