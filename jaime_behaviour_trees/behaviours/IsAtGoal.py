import py_trees
import math


class IsAtGoal(py_trees.behaviour.Behaviour):

    def __init__(self):

        super().__init__("IsAtGoal")


        self.bb = py_trees.blackboard.Client(
            name="IsAtGoal"
        )


        self.bb.register_key(
            key="goal_pose",
            access=py_trees.common.Access.READ
        )


        self.bb.register_key(
            key="robot_pose",
            access=py_trees.common.Access.READ
        )


        self.distance_tolerance = 0.3



    def update(self):


        try:

            goal = self.bb.goal_pose

            robot = self.bb.robot_pose


        except KeyError:


            return py_trees.common.Status.FAILURE



        distance = math.sqrt(
            (goal.pose.position.x -
             robot.pose.position.x)**2 +

            (goal.pose.position.y -
             robot.pose.position.y)**2
        )


        if distance < self.distance_tolerance:


            return py_trees.common.Status.SUCCESS


        return py_trees.common.Status.FAILURE