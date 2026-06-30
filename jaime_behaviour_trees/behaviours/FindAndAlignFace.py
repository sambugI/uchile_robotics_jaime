import py_trees


class FindAndAlignFace(
    py_trees.behaviour.Behaviour
):

    def __init__(self):

        super().__init__("FindAndAlignFace")

    def update(self):

        if self.face_aligned():

            return py_trees.common.Status.SUCCESS

        return py_trees.common.Status.RUNNING

    def face_aligned(self):

        return False