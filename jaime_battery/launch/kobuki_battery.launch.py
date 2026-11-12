from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    kobuki_battery_node = Node(
        package="jaime_battery",
        executable="kobuki_battery",
        name="kobuki_battery_node",
        output="screen",
        respawn=True,
        respawn_delay=2.0,
        # Descomenta la siguiente línea si el driver de Kobuki publica en /mobile_base/sensors/core
        # remappings=[("/sensors/core", "/mobile_base/sensors/core")],
    )

    return LaunchDescription([
        kobuki_battery_node,
    ])