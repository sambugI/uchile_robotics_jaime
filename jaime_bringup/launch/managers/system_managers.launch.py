#!/usr/bin/env python3

from launch import LaunchDescription
from launch.actions import TimerAction
from launch_ros.actions import Node


def generate_launch_description():

    # =========================
    # SYSTEM MANAGERS
    # =========================

    basic_manager = Node(
        package='jaime_bringup',
        executable='basic_manager.py',
        name='basic_manager',
        output='screen'
    )

    localization_manager = Node(
        package='jaime_bringup',
        executable='localization_manager.py',
        name='localization_manager',
        output='screen'
    )

    navigation_manager = Node(
        package='jaime_bringup',
        executable='navigation_manager.py',
        name='navigation_manager',
        output='screen'
    )

    tablet_manager = Node(
        package='jaime_bringup',
        executable='tablet_manager.py',
        name='tablet_manager',
        output='screen'
    )

    perception_manager = Node(
        package='jaime_bringup',
        executable='percepcion_manager.py',
        name='percepcion_manager',
        output='screen'
    )



    # Esperar a que el resto del sistema esté inicializado
    system_managers = TimerAction(
        period=20.0,
        actions=[
            basic_manager,
            localization_manager,
            navigation_manager,
            tablet_manager,
            perception_manager,
        ]
    )

    return LaunchDescription([
        system_managers,
    ])