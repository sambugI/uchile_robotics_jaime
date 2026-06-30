import py_trees
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

        pose = [0,0,0]

        if pose is None:

            return py_trees.common.Status.RUNNING

        self.bb.goal_pose = pose

        return py_trees.common.Status.SUCCESS