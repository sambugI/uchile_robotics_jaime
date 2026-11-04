import os
from glob import glob
from setuptools import setup

package_name = "jaime_joy"

setup(
    name=package_name,
    version="0.0.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (os.path.join("share", package_name, "launch"), glob("launch/*.launch.py")),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="root",
    maintainer_email="root@todo.todo",
    description="Package for joystick control",
    license="TODO: License declaration",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "jaime_teleop_node = jaime_joy.jaime_teleop_node:main",
            "quick_control_node = jaime_joy.quick_control_node:main",
        ],
    },
)
