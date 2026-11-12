import os
from glob import glob
from setuptools import find_packages, setup

package_name = 'jaime_battery'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='jaime',
    maintainer_email='jaime@todo.todo',
    description='Paquete para unificacion de baterias Kobuki y BMS JBD',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'battery_node = jaime_battery.battery_node:main',
            'kobuki_battery = jaime_battery.kobuki_battery_node:main'
        ],
    },
)