import py_trees

from behaviours.ReceiveMission import ReceiveMission
from behaviours.InitializeRobot import InitializeRobot
from behaviours.NeckSearchPose import NeckSearchPose
from behaviours.ObtainRobotLocalization import ObtainRobotLocalization
from behaviours.IsAtGoal import IsAtGoal
from behaviours.NavigateToGoal import NavigateToGoal
from behaviours.NeckConversationPose import NeckConversationPose
#from behaviours.FindAndAlignFace import FindAndAlignFace
from behaviours.Conversation import Conversation


def create_tree(node):

    #################################################
    # Árbol principal
    #################################################

    root = py_trees.composites.Sequence(
        name="MainMission",
        memory=True
    )

    #################################################
    # Navegación
    #################################################

    go_to_location = py_trees.composites.Selector(
        name="GoToRequestedLocation",
        memory=False
    )

    go_to_location.add_children([

        IsAtGoal(),

        NavigateToGoal(node)

    ])

    #################################################
    # Buscar usuario
    #################################################

    """acquire_user = py_trees.composites.Sequence(
        name="AcquireUser",
        memory=True
    )

    acquire_user.add_children([

        NeckConversationPose(node),

        FindAndAlignFace(node)

    ]) """

    #################################################
    # Misión principal
    #################################################

    root.add_children([

        ReceiveMission(),

        # InitializeRobot(node),

        # NeckSearchPose(node),

        ObtainRobotLocalization(node),

        go_to_location,

        # acquire_user,

        # Conversation()

    ])

    return root
