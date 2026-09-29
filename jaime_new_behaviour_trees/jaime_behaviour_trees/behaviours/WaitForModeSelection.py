import py_trees

class WaitForModeSelection(py_trees.behaviour.Behaviour):

    def __init__(self, node):

        super().__init__(
            name="WaitForModeSelection"
        )

        self.node = node

        self.blackboard = py_trees.blackboard.Client(
            name="ModeSelection"
        )

        self.blackboard.register_key(
            key="mode",
            access=py_trees.common.Access.WRITE
        )

    def update(self):

        # TODO:
        # Obtener selección desde la tablet

        selection = None

        if selection == "teleop":

            self.blackboard.mode = "TELEOP"

            return py_trees.common.Status.SUCCESS

        if selection == "demo":

            self.blackboard.mode = "DEMO"

            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.RUNNING