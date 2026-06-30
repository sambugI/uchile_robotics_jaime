import py_trees


class IsAtGoal(py_trees.behaviour.Behaviour):

    def __init__(self):

        super().__init__("IsAtGoal")

        self.bb = py_trees.blackboard.Client(
            name="IsAtGoal"
        )

        self.bb.register_key(
            key="goal_pose",
            access=py_trees.common.Access.READ
        )

    def update(self):

        if self.goal_reached():

            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.FAILURE

    def goal_reached(self):

        return False