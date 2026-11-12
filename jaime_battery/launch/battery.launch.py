import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='jaime_battery',
            executable='battery_node',
            name='jaime_battery_node',
            output='screen',
            parameters=[{
                'jbd_port': '/dev/battery_bms',
                'jbd_baudrate': 9600,
                'kobuki_topic': '/sensors/battery_state',
                'publish_rate': 1.0
            }]
        )
    ])