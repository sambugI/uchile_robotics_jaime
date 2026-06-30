from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Nodo personalizado de bender_manipulation
    my_node = Node(
        package='jaime_manipulation',
        executable='dynamixel_node.py',  # Reemplaza con el nombre real del ejecutable
        name='jaime_joint_controller',
        output='screen'
    )

    return LaunchDescription([
        my_node
    ])
