#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

import py_trees
from Demo_mode import create_tree_demo


def main():

    rclpy.init()

    node = Node("jaime_behaviour_tree")

    root = create_tree_demo(node)

    tree = py_trees.trees.BehaviourTree(root)

    tree.setup(timeout=15)

    try:

        while rclpy.ok():

            # Ejecutar un tick
            tree.tick()

            # Procesar callbacks de ROS
            rclpy.spin_once(
                node,
                timeout_sec=0.1
            )

            # Revisar estado del árbol
            if root.status == py_trees.common.Status.SUCCESS:
                node.get_logger().info(
                    "Mission completed successfully"
                )
                break

            elif root.status == py_trees.common.Status.FAILURE:
                node.get_logger().error(
                    "Mission failed"
                )
                break

    except KeyboardInterrupt:

        pass

    finally:

        tree.shutdown()

        node.destroy_node()

        rclpy.shutdown()


if __name__ == "__main__":
    main()
