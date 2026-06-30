import py_trees


class NeckSearchPose(py_trees.behaviour.Behaviour):

    def __init__(self):
        super().__init__("NeckSearchPose")

    def initialise(self):

        self.goal_sent = False

    def update(self):

        if not self.goal_sent:

            # enviar pose al cuello

            self.goal_sent = True

            return py_trees.common.Status.RUNNING

        if self.pose_reached():

            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.RUNNING

    def pose_reached(self):
        return True