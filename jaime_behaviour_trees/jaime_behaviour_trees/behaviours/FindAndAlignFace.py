import py_trees

import rclpy
from rclpy.action import ActionClient

from jaime_interfaces.action import FindFace


class FindAndAlignFace(py_trees.behaviour.Behaviour):

    def __init__(self, node):

        super().__init__("FindAndAlignFace")

        self.node = node

        self.action_client = ActionClient(
            node,
            FindFace,
            "/perception/find_face"
        )

        self.goal_sent = False

        self.goal_handle = None

        self.result_future = None

    def initialise(self):

        self.goal_sent = False
        self.goal_handle = None
        self.result_future = None

    def update(self):

        #################################################
        # Esperar servidor
        #################################################

        if not self.action_client.server_is_ready():

            return py_trees.common.Status.RUNNING

        #################################################
        # Enviar goal
        #################################################

        if not self.goal_sent:

            goal = FindFace.Goal()

            goal.tolerance = 0.05

            future = self.action_client.send_goal_async(goal)

            future.add_done_callback(
                self.goal_response_callback
            )

            self.goal_sent = True

            return py_trees.common.Status.RUNNING

        #################################################
        # Esperar resultado
        #################################################

        if self.result_future is None:

            return py_trees.common.Status.RUNNING

        if not self.result_future.done():

            return py_trees.common.Status.RUNNING

        result = self.result_future.result().result

        if result.success:

            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.FAILURE


    def goal_response_callback(self, future):

        self.goal_handle = future.result()

        if not self.goal_handle.accepted:

            return

        self.result_future = (
            self.goal_handle.get_result_async()
        )