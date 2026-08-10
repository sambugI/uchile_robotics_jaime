# en rviz2:
# - Fixed Frame: map
# - Map durability policy: transient local
# - Si no sale el lidar:
#       Add -> Topic -> scan_raw -> LaserScan
# - La imagen de la tablet puede demorar en aparecer


from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch.substitutions import PathJoinSubstitution

from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node
from launch.actions import TimerAction



def generate_launch_description():

    bringup_pkg = FindPackageShare('jaime_bringup')
    description_pkg = FindPackageShare('jaime_description')
    tablet_pkg = FindPackageShare('jaime_tablet')
    manipulation_pkg = FindPackageShare('jaime_manipulation')


    # -------------------------
    # Robot description + RVIZ
    # -------------------------

    display_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                description_pkg,
                'launch',
                'display.launch.py'
            ])
        ),
        launch_arguments={
            'use_sim_time': 'false',
            'rviz': 'true'
        }.items()
    )


    # -------------------------
    # Basic robot
    # motores, sensores, TF, lidar, odom
    # -------------------------

    basic_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                bringup_pkg,
                'launch',
                'robot',
                'jaime_basic.launch.py'
            ])
        )
    )


    # -------------------------
    # Localization AMCL + map server
    # -------------------------

    localization_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                bringup_pkg,
                'launch',
                'localization',
                'localization_launch.py'
            ])
        )
    )


    # -------------------------
    # Navigation Nav2
    # -------------------------

    navigation_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                bringup_pkg,
                'launch',
                'navigation',
                'navigation_launch.py'
            ])
        )
    )


    # -------------------------
    # Tablet
    # android_cam
    # media_sender
    # file_publisher
    # -------------------------

    tablet_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                tablet_pkg,
                'tablet_launch.py'
            ])
        )
    )


    # -------------------------
    # Manipulación
    # dynamixel
    # encoders
    # local planner
    # -------------------------

    manipulation_node = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                manipulation_pkg,
                'launch',
                'jaime_manipulation.launch.py'
            ])
        )
    )
    #face_node = IncludeLaunchDescription(
    #    PythonLaunchDescriptionSource(
    #        PathJoinSubstitution([
    #            manipulation_pkg,
    #            'launch',
    #            'face_launch.py'
    #        ])
    #    )
    #)
    return LaunchDescription([

        # Robot
        display_node,
        basic_node,
        localization_node,
        navigation_node,

        # Peripherals
        tablet_node,
        manipulation_node,
        #face_node,

    ])
