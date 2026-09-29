import py_trees

class IsMode(py_trees.behaviour.Behaviour):

    def __init__(self, mode):
        super().__init__(name=f"IsMode_{mode}")

        self.mode = mode

        self.blackboard = py_trees.blackboard.Client(
            name=f"IsMode_{mode}"
        )

        self.blackboard.register_key(
            key="mode",
            access=py_trees.common.Access.READ
        )

    def update(self):

        if self.blackboard.mode == self.mode:
            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.FAILURE


def create_tree(node):

    #################################################
    # Blackboard
    #################################################

    blackboard = py_trees.blackboard.Client(
        name="RobotState"
    )

    blackboard.register_key(
        key="mode",
        access=py_trees.common.Access.WRITE
    )

    blackboard.register_key(
        key="emergency",
        access=py_trees.common.Access.WRITE
    )

    # Estado inicial
    blackboard.mode = "IDLE"
    blackboard.emergency = False

    #################################################
    # Emergency
    #################################################

    emergency = EmergencyMode(node)

    #################################################
    # Idle
    #################################################

    idle = py_trees.composites.Sequence(
        name="IdleMode",
        memory=False
    )

    idle.add_children([
        IsMode("IDLE"),
        IdleMode(node)
    ])

    #################################################
    # Teleoperation
    #################################################

    teleoperation = py_trees.composites.Sequence(
        name="TeleoperationMode",
        memory=False
    )

    teleoperation.add_children([
        IsMode("TELEOP"),
        TeleoperationMode(node)
    ])

    #################################################
    # Demo
    #################################################

    demo = py_trees.composites.Sequence(
        name="DemoMode",
        memory=False
    )

    demo.add_children([
        IsMode("DEMO"),
        DemoMode(node)
    ])

    #################################################
    # Selector de modos
    #################################################

    mode_selector = py_trees.composites.Selector(
        name="ModeSelector",
        memory=False
    )

    mode_selector.add_children([
        idle,
        teleoperation,
        demo
    ])

    #################################################
    # Árbol principal
    #################################################

    root = py_trees.composites.Selector(
        name="MainRobot",
        memory=False
    )

    root.add_children([
        emergency,
        mode_selector
    ])

    return root
