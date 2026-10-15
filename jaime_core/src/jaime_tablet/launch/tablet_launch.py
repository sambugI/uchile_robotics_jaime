#la idea es que inicie la camara y el envio de imagenes
#funciona file_publisher
#funciona media_sender_node
#funciona android_cam
#se debe activar IP webcam en la tablet primero

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare
from launch_ros.actions import Node
from launch.substitutions import Command, LaunchConfiguration
from launch.actions import TimerAction

"""def generate_launch_description():

    #package jaime_tablet
    tablet_pkg = FindPackageShare('jaime_tablet')

    android_cam_node = Node(
        package='jaime_tablet',
        executable='android_cam',
        output='screen'
    )

    media_sender_node = Node(
        package='jaime_tablet',
        executable='media_sender',
        output='screen' 
    )

    file_publisher_node = Node(
        package='jaime_tablet',
        executable='file_publisher',
        parameters=[{
            'path': PathJoinSubstitution([
                tablet_pkg,
                'imagenes',
                'pato.gif'
            ])
        }],
        output='screen'
    )


    return LaunchDescription([
        android_cam_node,
        media_sender_node,
        file_publisher_node,
    ])"""

def generate_launch_description():

    # Iniciar ADB y los servidores WebSocket/WebRTC
    iniciar_servidores_node = Node(
        package='jaime_tablet',
        executable='iniciar_servidores',
        name='iniciar_servidores',
        output='screen'
    )

    # Cámara WebRTC: publica las imágenes en image_raw
    webrtc_cam_node = Node(
        package='jaime_tablet',
        executable='webRTC_cam',
        name='webrtc_camera',
        output='screen'
    )

    # Esperar antes de iniciar la cámara
    iniciar_camara = TimerAction(
        period=3.0,
        actions=[webrtc_cam_node]
    )

    return LaunchDescription([
        iniciar_servidores_node,
        iniciar_camara,
    ])
