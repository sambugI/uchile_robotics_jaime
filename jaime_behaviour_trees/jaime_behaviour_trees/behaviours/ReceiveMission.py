import py_trees

from geometry_msgs.msg import PoseStamped


class ReceiveMission(
    py_trees.behaviour.Behaviour
):

    def __init__(self):

        super().__init__("ReceiveMission")

        self.bb = py_trees.blackboard.Client(
            name="MissionWriter"
        )

        self.bb.register_key(
            key="goal_pose",
            access=py_trees.common.Access.WRITE
        )


    def update(self):

        pose = PoseStamped()

        pose.header.frame_id = "map"

        pose.pose.position.x = 1.0713979281359092
        pose.pose.position.y = 2.3921611174592865
        pose.pose.position.z = 0.0

        pose.pose.orientation.x = 0.0
        pose.pose.orientation.y = 0.0
        pose.pose.orientation.z = 0.7072878800407808
        pose.pose.orientation.w = 0.7069256359387585

        self.bb.goal_pose = pose

        return py_trees.common.Status.SUCCESS
