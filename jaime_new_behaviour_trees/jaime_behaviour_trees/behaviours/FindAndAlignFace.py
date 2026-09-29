#!/usr/bin/env python3

import py_trees

from action_msgs.msg import GoalStatus

from rclpy.action import ActionClient

from jaime_interfaces.action import FindFace


class FindAndAlignFace(py_trees.behaviour.Behaviour):

    def __init__(self, node):

        super().__init__("FindAndAlignFace")

        self.node = node

        self.action_client = ActionClient(
            self.node,
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

        if not self.action_client.wait_for_server(
            timeout_sec=0.1
        ):

            self.node.get_logger().warn(
                "Waiting for FindFace action server"
            )

            return py_trees.common.Status.RUNNING


        #################################################
        # Enviar objetivo
        #################################################

        if not self.goal_sent:

            goal = FindFace.Goal()

            goal.tolerance = 0.05

            self.node.get_logger().info(
                "Sending FindFace goal"
            )

            future = self.action_client.send_goal_async(
                goal
            )

            future.add_done_callback(
                self.goal_response_callback
            )

            self.goal_sent = True

            return py_trees.common.Status.RUNNING


        #################################################
        # Esperar aceptación
        #################################################

        if self.goal_handle is None:

            return py_trees.common.Status.RUNNING


        #################################################
        # Esperar resultado
        #################################################

        if self.result_future is None:

            return py_trees.common.Status.RUNNING

        if not self.result_future.done():

            return py_trees.common.Status.RUNNING

        result = self.result_future.result()

        if result is None:

            self.node.get_logger().error(
                "FindFace action failed"
            )

            return py_trees.common.Status.FAILURE


        #################################################
        # Resultado
        #################################################

        if result.status == GoalStatus.STATUS_SUCCEEDED:

            if result.result.success:

                self.node.get_logger().info(
                    "Face found and aligned"
                )

                return py_trees.common.Status.SUCCESS

            self.node.get_logger().error(
                result.result.message
            )

            return py_trees.common.Status.FAILURE


        self.node.get_logger().error(
            f"FindFace failed with status {result.status}"
        )

        return py_trees.common.Status.FAILURE


    #################################################
    # Callback de aceptación
    #################################################

    def goal_response_callback(self, future):

        self.goal_handle = future.result()

        if self.goal_handle is None:

            return

        if not self.goal_handle.accepted:

            self.node.get_logger().error(
                "FindFace goal rejected"
            )

            self.goal_handle = None

            return

        self.node.get_logger().info(
            "FindFace goal accepted"
        )

        self.result_future = (
            self.goal_handle.get_result_async()
        )


    #################################################
    # Cancelación
    #################################################

    def terminate(self, new_status):

        if (
            self.goal_handle is not None
            and new_status == py_trees.common.Status.INVALID
        ):

            self.node.get_logger().info(
                "Canceling FindFace goal"
            )

            self.goal_handle.cancel_goal_async()