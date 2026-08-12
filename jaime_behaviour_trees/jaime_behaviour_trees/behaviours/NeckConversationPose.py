#!/usr/bin/env python3

import py_trees
from action_msgs.msg import GoalStatus
from rclpy.action import ActionClient
from jaime_interfaces.action import MoveToJointPose



class NeckConversationPose(py_trees.behaviour.Behaviour):

    def __init__(self, node):

        super().__init__("NeckConversationPose")

        self.node = node


        self.action_client = ActionClient(
            self.node,
            MoveToJointPose,
            "/manipulation/move_to_joint_pose"
        )


        self.goal_sent = False
        self.goal_handle = None
        self.result_future = None


        # Pose de conversación
        # TODO: cambiar según calibración

        self.conversation_pose = [0.03, 0.07, -1.16182676]



    def initialise(self):

        self.goal_sent = False
        self.goal_handle = None
        self.result_future = None



    def update(self):


        #################################################
        # Esperar servidor de manipulación
        #################################################

        if not self.action_client.wait_for_server(
            timeout_sec=0.1
        ):

            self.node.get_logger().warn(
                "Waiting for manipulation action server"
            )

            return py_trees.common.Status.RUNNING



        #################################################
        # Enviar objetivo
        #################################################

        if not self.goal_sent:
            goal = MoveToJointPose.Goal()
            goal.joints = self.conversation_pose
            self.node.get_logger().info(
                "Sending neck conversation pose"
            )
            future = (
                self.action_client
                .send_goal_async(goal)
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
                "Manipulation action failed"
            )

            return py_trees.common.Status.FAILURE



        #################################################
        # Resultado
        #################################################

        if result.status == GoalStatus.STATUS_SUCCEEDED:


            if result.result.success:

                self.node.get_logger().info(
                    "Neck reached conversation pose"
                )

                return py_trees.common.Status.SUCCESS


            self.node.get_logger().error(
                result.result.message
            )

            return py_trees.common.Status.FAILURE



        self.node.get_logger().error(
            f"Neck movement failed with status {result.status}"
        )

        return py_trees.common.Status.FAILURE



    #################################################
    # Callback aceptación
    #################################################

    def goal_response_callback(self, future):


        self.goal_handle = future.result()


        if self.goal_handle is None:

            return


        if not self.goal_handle.accepted:


            self.node.get_logger().error(
                "Neck conversation goal rejected"
            )


            self.goal_handle = None

            return



        self.node.get_logger().info(
            "Neck conversation goal accepted"
        )


        self.result_future = (
            self.goal_handle
            .get_result_async()
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
                "Canceling neck conversation goal"
            )

            self.goal_handle.cancel_goal_async()