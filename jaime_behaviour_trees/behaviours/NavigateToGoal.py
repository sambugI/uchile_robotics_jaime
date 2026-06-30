import py_trees


class NavigateToGoal(
    py_trees.behaviour.Behaviour
):

    def __init__(self):

        super().__init__("NavigateToGoal")

        self.goal_sent = False
        self.reader = py_trees.blackboard.Client(name="Reader")
        self.reader.register_key(key="goal_pose", access=py_trees.common.Access.READ)
    
    def initialise(self):

        self.goal_sent = False

        try:
            self.goal = self.reader.goal_pose
            self.goal_available = True

        except KeyError:
            self.goal_available = False

    def update(self):
        if not self.goal_available:
            return py_trees.common.Status.FAILURE
        if not self.goal_sent:

            self.send_goal()

            self.goal_sent = True

            return py_trees.common.Status.RUNNING

        if self.navigation_finished():

            if self.navigation_success():

                return py_trees.common.Status.SUCCESS

            return py_trees.common.Status.FAILURE

        return py_trees.common.Status.RUNNING

    def send_goal(self):
        pass

    def navigation_finished(self):
        return False

    def navigation_success(self):
        return True