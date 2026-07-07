from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():

    dynamixel_publish = Node(
        package='jaime_manipulation',
        executable='dynamixel_publish',
        name='dynamixel_publish',
        output='screen'
    )

    read_encoders = Node(
        package='jaime_manipulation',
        executable='read_encoders',
        name='read_encoders',
        output='screen'
    )

    local_planner = Node(
        package='jaime_manipulation',
        executable='local_planner',
        name='local_planner',
        output='screen'
    )

    return LaunchDescription([
        dynamixel_publish,
        read_encoders,
        local_planner,
    ])