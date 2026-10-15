import py_trees

# ============================================================
# Skills existentes
# ============================================================

from behaviours.InitializeRobot import InitializeRobot
from behaviours.NeckSearchPose import NeckSearchPose
from behaviours.ObtainRobotLocalization import ObtainRobotLocalization
from behaviours.IsAtGoal import IsAtGoal
from behaviours.NavigateToGoal import NavigateToGoal
from behaviours.NeckConversationPose import NeckConversationPose
from behaviours.Conversation import Conversation


# ============================================================
# Behaviours por desarrollar
# ============================================================

from behaviours.GetDestinationFromConversation import GetDestinationFromConversation
from behaviours.FindAndAlignFace import FindAndAlignFace
from behaviours.RoomConversation import RoomConversation
from behaviours.DetectInteractionEnd import DetectInteractionEnd
from behaviours.ReturnToInitialPose import ReturnToInitialPose


def create_tree_demo(node):

    initialize_robot = InitializeRobot(node)

    initial_conversation = Conversation(node)
    #get_destination = GetDestinationFromConversation(node)

    neck_search_pose = NeckSearchPose(node)

    localization = ObtainRobotLocalization(node)

    go_to_location = py_trees.composites.Selector(
        name="GoToRequestedLocation",
        memory=False
    )
    go_to_location.add_children([
        IsAtGoal(),
        NavigateToGoal(node)
    ])

    neck_conversation_pose = NeckConversationPose(node)
    find_and_align_face = FindAndAlignFace(node)
    #room_conversation = RoomConversation(node)
    #interaction_end = DetectInteractionEnd(node)
    #return_to_initial_pose = ReturnToInitialPose(node)
    root = py_trees.composites.Sequence(
        name="MainDemo",
        memory=True
    )

    root.add_children([
        initialize_robot,
        #initial_conversation,
        #get_destination,
        neck_search_pose,
        localization,
        go_to_location,
        neck_conversation_pose,
        find_and_align_face,
        #room_conversation,
        #interaction_end,
        #return_to_initial_pose
    ])
    return root