import py_trees


class Conversation(
    py_trees.behaviour.Behaviour
):

    def __init__(self):

        super().__init__("Conversation")

    def initialise(self):

        self.start_conversation()

    def update(self):

        if self.finished():

            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.RUNNING

    def start_conversation(self):
        pass

    def finished(self):
        return False