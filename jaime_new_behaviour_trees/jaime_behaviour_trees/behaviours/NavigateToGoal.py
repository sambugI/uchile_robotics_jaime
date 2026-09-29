#!/usr/bin/env python3

import py_trees

from action_msgs.msg import GoalStatus

from rclpy.action import ActionClient

from nav2_msgs.action import NavigateToPose


class NavigateToGoal(py_trees.behaviour.Behaviour):

    def __init__(self, node):

        super().__init__("NavigateToGoal")

        self.node = node

        # Blackboard

        self.bb = py_trees.blackboard.Client(
            name="NavigateToGoal"
        )

        self.bb.register_key(
            key="goal_pose",
            access=py_trees.common.Access.READ
        )

        # Cliente de acción Nav2

        self.action_client = ActionClient(
            self.node,
            NavigateToPose,
            "/navigate_to_pose"
        )

        self.goal_sent = False
        self.goal_handle = None
        self.result_future = None
        self.goal_pose = None


    def initialise(self):

        self.goal_sent = False
        self.goal_handle = None
        self.result_future = None

        try:

            self.goal_pose = self.bb.goal_pose

        except KeyError:

            self.node.get_logger().error(
                "goal_pose not found in blackboard"
            )


    def update(self):

        #################################################
        # Revisar objetivo
        #################################################

        if self.goal_pose is None:

            return py_trees.common.Status.FAILURE

        #################################################
        # Esperar servidor
        #################################################

        if not self.action_client.wait_for_server(
            timeout_sec=0.1
        ):

            self.node.get_logger().warn(
                "Waiting for Nav2 action server"
            )

            return py_trees.common.Status.RUNNING

        #################################################
        # Enviar objetivo
        #################################################

        if not self.goal_sent:

            goal = NavigateToPose.Goal()

            goal.pose = self.goal_pose

            self.node.get_logger().info(
                "Sending navigation goal"
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

            return py_trees.common.Status.FAILURE

        #################################################
        # Resultado
        #################################################

        if result.status == GoalStatus.STATUS_SUCCEEDED:

            self.node.get_logger().info(
                "Navigation succeeded"
            )

            return py_trees.common.Status.SUCCESS

        self.node.get_logger().error(
            f"Navigation failed with status {result.status}"
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
                "Navigation goal rejected"
            )

            self.goal_handle = None

            return

        self.node.get_logger().info(
            "Navigation goal accepted"
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
                "Canceling navigation goal"
            )

            self.goal_handle.cancel_goal_async()