import py_trees


class NeckConversationPose(
    py_trees.behaviour.Behaviour
):

    def __init__(self):

        super().__init__("NeckConversationPose")

    def update(self):

        if self.reached():

            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.RUNNING

    def reached(self):
        return True