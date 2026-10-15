import py_trees

from std_msgs.msg import Bool


class EmergencyMode(py_trees.behaviour.Behaviour):

    def __init__(self, node):

        super().__init__(
            name="EmergencyMode"
        )

        self.node = node

        #################################################
        # Estado de emergencia
        #################################################

        self.emergency = False

        #################################################
        # Subscriber
        #################################################

        self.subscription = self.node.create_subscription(
            Bool,
            "/emergency_state",
            self.emergency_callback,
            10
        )

    #################################################
    # Callback
    #################################################

    def emergency_callback(self, msg):

        self.emergency = msg.data

    #################################################
    # Behaviour
    #################################################

    def update(self):

        #################################################
        # Emergencia activa
        #################################################

        if self.emergency:

            return py_trees.common.Status.RUNNING

        #################################################
        # No hay emergencia
        #################################################

        return py_trees.common.Status.SUCCESS

    #################################################
    # Finalización
    #################################################

    def terminate(self, new_status):

        self.node.get_logger().info(
            "Emergency mode terminated"
        )