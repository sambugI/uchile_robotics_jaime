import py_trees

from behaviours.InitializeRobot import InitializeRobot
from behaviours.NeckSearchPose import NeckSearchPose
from behaviours.ObtainRobotLocalization import ObtainRobotLocalization
from behaviours.IsAtGoal import IsAtGoal
from behaviours.NavigateToGoal import NavigateToGoal
from behaviours.NeckConversationPose import NeckConversationPose
from behaviours.FindAndAlignFace import FindAndAlignFace
from behaviours.Conversation import Conversation
from behaviours.ReceiveMission import ReceiveMission



def create_tree():

    root = py_trees.composites.Sequence(
        name="MainMission",
        memory=True
    )

    go_to_location = py_trees.composites.Selector(
        name="GoToRequestedLocation",
        memory=False
    )

    go_to_location.add_children([
        IsAtGoal(),
        NavigateToGoal()  
    ])

    acquire_user = py_trees.composites.Sequence(
        name="AcquireUser",
        memory=True
    )

    acquire_user.add_children([
        NeckConversationPose(),
        FindAndAlignFace()
    ])

    root.add_children([
        ReceiveMission,
        InitializeRobot(), # Se va a verificar solo que el robot funcione, el full launch se debe hacer afuera
        NeckSearchPose(),
        ObtainRobotLocalization(), #Recuerda que el robot se debe localizar solo usando amcl.
        go_to_location,
        acquire_user,
        Conversation()
    ])

    return root