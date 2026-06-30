import py_trees


class ObtainRobotLocalization(
    py_trees.behaviour.Behaviour
):

    def __init__(self):

        super().__init__("ObtainRobotLocalization")

    def update(self):

        if self.robot_localized():

            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.RUNNING

    def robot_localized(self):

        # verificar AMCL
        # verificar covarianza
        # verificar TF

        return True