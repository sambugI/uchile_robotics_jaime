import py_trees

from std_msgs.msg import Bool


class TeleoperationMode(py_trees.behaviour.Behaviour):

    def __init__(self, node):

        super().__init__(
            name="TeleoperationMode"
        )

        self.node = node

        #################################################
        # Blackboard
        #################################################

        self.blackboard = py_trees.blackboard.Client(
            name="TeleoperationMode"
        )

        self.blackboard.register_key(
            key="mode",
            access=py_trees.common.Access.WRITE
        )

        #################################################
        # Estado
        #################################################

        self.finished = False

        #################################################
        # Subscriber
        #################################################

        self.subscription = self.node.create_subscription(
            Bool,
            "/teleoperation/finished",
            self.teleoperation_finished_callback,
            10
        )

    #################################################
    # Callback
    #################################################

    def teleoperation_finished_callback(self, msg):

        if msg.data:
            self.finished = True

    #################################################
    # Behaviour
    #################################################

    def initialise(self):

        self.finished = False

        self.node.get_logger().info(
            "Teleoperation mode started"
        )

    def update(self):

        #################################################
        # Esperar mensaje de término
        #################################################

        if not self.finished:

            return py_trees.common.Status.RUNNING

        #################################################
        # Teleoperación terminada
        #################################################

        self.node.get_logger().info(
            "Teleoperation finished"
        )

        self.blackboard.mode = "IDLE"

        return py_trees.common.Status.SUCCESS

    #################################################
    # Finalización
    #################################################

    def terminate(self, new_status):

        self.node.get_logger().info(
            "Teleoperation mode terminated"
        )