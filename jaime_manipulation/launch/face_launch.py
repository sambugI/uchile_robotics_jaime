from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    face_detector = Node(
        package='jaime_manipulation',
        executable='face_detector.py',
        name='face_detector',
        output='screen'
    )

    face_tracker = Node(
        package='jaime_manipulation',
        executable='face_follower.py',
        name='face_follower',
        output='screen'
    )

    return LaunchDescription([
        face_detector,
        face_tracker,
    ])
