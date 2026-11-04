from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='jaime_joy',
            executable='quick_control_node',
            name='quick_control_node',
            output='screen'
        )
    ])
