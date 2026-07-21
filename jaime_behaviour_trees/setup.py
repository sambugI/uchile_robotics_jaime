from setuptools import find_packages, setup

package_name = "jaime_behaviour_trees"

setup(
    name=package_name,
    version="0.0.1",
    packages=find_packages(),
    data_files=[
        (
            "share/ament_index/resource_index/packages",
            ["resource/" + package_name],
        ),
        (
            "share/" + package_name,
            ["package.xml"],
        ),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="jaime",
    maintainer_email="you@example.com",
    description="Behaviour Trees",
    license="Apache-2.0",
    entry_points={
        "console_scripts": [
            "mission_tree = jaime_behaviour_trees.main:main",
        ],
    },
)
