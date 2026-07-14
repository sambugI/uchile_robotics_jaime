import py_trees

import rclpy

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


        # Nav2 Action Client

        self.action_client = ActionClient(
            self.node,
            NavigateToPose,
            "/navigate_to_pose"
        )


        self.goal_sent = False

        self.goal_handle = None

        self.result_future = None



    def initialise(self):

        self.goal_sent = False

        self.goal_handle = None

        self.result_future = None



        # Revisar que exista goal

        try:

            self.goal_pose = self.bb.goal_pose


        except KeyError:

            self.node.get_logger().error(
                "goal_pose not found in blackboard"
            )

            return



    def update(self):


        # --------------------------
        # Esperar servidor Nav2
        # --------------------------

        if not self.action_client.wait_for_server(
            timeout_sec=0.1
        ):


            self.node.get_logger().warn(
                "Waiting for Nav2 action server"
            )

            return py_trees.common.Status.RUNNING



        # --------------------------
        # Enviar objetivo
        # --------------------------

        if not self.goal_sent:


            goal = NavigateToPose.Goal()


            goal.pose = self.goal_pose



            self.node.get_logger().info(
                "Sending goal to Nav2"
            )



            send_future = (
                self.action_client
                .send_goal_async(goal)
            )


            send_future.add_done_callback(
                self.goal_response_callback
            )


            self.goal_sent = True


            return py_trees.common.Status.RUNNING



        # --------------------------
        # Esperando aceptación
        # --------------------------

        if self.goal_handle is None:


            return py_trees.common.Status.RUNNING



        # --------------------------
        # Esperando resultado
        # --------------------------

        if self.result_future is None:


            return py_trees.common.Status.RUNNING



        if not self.result_future.done():


            return py_trees.common.Status.RUNNING



        result = self.result_future.result()



        status = result.status



        # Nav2 SUCCEEDED

        if status == 4:


            self.node.get_logger().info(
                "Navigation succeeded"
            )


            return py_trees.common.Status.SUCCESS



        else:


            self.node.get_logger().error(
                f"Navigation failed with status {status}"
            )


            return py_trees.common.Status.FAILURE



    # -------------------------------------------------
    # Callback cuando Nav2 acepta/rechaza el objetivo
    # -------------------------------------------------

    def goal_response_callback(self, future):


        self.goal_handle = future.result()



        if not self.goal_handle.accepted:


            self.node.get_logger().error(
                "Nav2 rejected goal"
            )

            self.goal_handle = None

            return



        self.node.get_logger().info(
            "Nav2 accepted goal"
        )


        self.result_future = (
            self.goal_handle
            .get_result_async()
        )



    # -------------------------------------------------
    # Cancelación si el árbol cambia de estado
    # -------------------------------------------------

    def terminate(self, new_status):


        if self.goal_handle is not None:


            if new_status == py_trees.common.Status.INVALID:


                self.node.get_logger().info(
                    "Canceling navigation goal"
                )


                self.goal_handle.cancel_goal_async()