#!/usr/bin/env python3

import time
import numpy as np

import rclpy

from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.task import Future

from sensor_msgs.msg import JointState
from std_msgs.msg import Float64MultiArray

from jaime_interfaces.action import MoveToJointPose


class JointPoseActionServer(Node):

    def __init__(self):

        super().__init__(
            "joint_pose_action_server"
        )


        #################################################
        # Callback group para multithreading
        #################################################

        self.callback_group = ReentrantCallbackGroup()


        #################################################
        # Variables de acción
        #################################################

        self.active_goal = None
        self.active_goal_handle = None
        self.result_future = None


        #################################################
        # Estado robot
        #################################################

        self.current_joints = None

        self.last_joint_time = time.time()


        self.goal_tolerance = 0.015


        #################################################
        # Publicador objetivo
        #################################################

        self.goal_pub = self.create_publisher(
            Float64MultiArray,
            "joint_goal",
            10
        )


        #################################################
        # Joint states
        #################################################

        self.joint_sub = self.create_subscription(
            JointState,
            "joint_states",
            self.joint_state_callback,
            10,
            callback_group=self.callback_group
        )


        #################################################
        # Timer controlador
        #################################################

        self.control_timer = self.create_timer(
            0.05,
            self.control_loop,
            callback_group=self.callback_group
        )


        #################################################
        # Action Server
        #################################################

        self.action_server = ActionServer(
            self,
            MoveToJointPose,
            "/manipulation/move_to_joint_pose",
            self.execute_callback,
            callback_group=self.callback_group
        )



    #################################################
    # Joint states
    #################################################

    def joint_state_callback(self,msg):

        if len(msg.position) < 5:
            return


        self.current_joints = np.array([
            msg.position[0],
            msg.position[3],
            msg.position[4]
        ])


        self.last_joint_time = time.time()



    #################################################
    # Action callback
    #################################################

    async def execute_callback(self,goal_handle):

        self.get_logger().info(
            "Nueva pose recibida"
        )


        if self.active_goal is not None:

            goal_handle.abort()

            result = MoveToJointPose.Result()

            result.success=False
            result.message="Ya existe una acción activa"

            return result



        target = list(
            goal_handle.request.joints
        )


        if len(target)!=3:

            goal_handle.abort()

            result = MoveToJointPose.Result()

            result.success=False
            result.message="Se esperaban 3 joints"

            return result



        #################################################
        # Guardar objetivo
        #################################################

        self.active_goal = np.array(target)

        self.active_goal_handle = goal_handle


        self.result_future = Future()



        self.get_logger().info(
            f"Nuevo objetivo: {target}"
        )



        #################################################
        # Esperar que control_loop termine
        #################################################

        result = await self.result_future


        return result




    #################################################
    # Control loop
    #################################################

    def control_loop(self):


        if self.active_goal is None:
            return



        #################################################
        # Publicar objetivo
        #################################################

        msg = Float64MultiArray()

        msg.data = (
            self.active_goal.tolist()
        )

        self.goal_pub.publish(msg)



        #################################################
        # Revisar joint states
        #################################################

        if self.current_joints is None:
            return



        if time.time() - self.last_joint_time > 1.0:


            self.finish_action(
                False,
                "No se reciben joint states",
                abort=True
            )

            return



        #################################################
        # Error
        #################################################

        error = np.linalg.norm(
            self.active_goal -
            self.current_joints
        )



        #################################################
        # Feedback
        #################################################

        feedback = MoveToJointPose.Feedback()

        feedback.error = float(error)


        self.active_goal_handle.publish_feedback(
            feedback
        )



        #################################################
        # Éxito
        #################################################

        if error < self.goal_tolerance:


            self.finish_action(
                True,
                "Joint pose alcanzada"
            )


            return



        #################################################
        # Cancelación
        #################################################

        if self.active_goal_handle.is_cancel_requested:


            self.active_goal_handle.canceled()


            self.finish_action(
                False,
                "Movimiento cancelado"
            )




    #################################################
    # Finalizar acción
    #################################################

    def finish_action(
        self,
        success,
        message,
        abort=False
    ):


        if self.active_goal_handle is None:
            return



        result = MoveToJointPose.Result()

        result.success = success

        result.message = message



        if abort:

            self.active_goal_handle.abort()

        elif success:

            self.active_goal_handle.succeed()



        self.result_future.set_result(
            result
        )



        self.active_goal = None
        self.active_goal_handle = None
        self.result_future = None




#################################################
# MAIN
#################################################

def main(args=None):

    rclpy.init(args=args)


    node = JointPoseActionServer()



    executor = MultiThreadedExecutor(
        num_threads=3
    )


    executor.add_node(node)


    try:

        executor.spin()


    except KeyboardInterrupt:

        pass


    finally:

        node.destroy_node()

        rclpy.shutdown()



if __name__=="__main__":

    main()