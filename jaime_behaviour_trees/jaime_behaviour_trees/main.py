#!/usr/bin/env python3

import rclpy

from rclpy.node import Node

import py_trees

from mission_tree import create_tree


def main():

    rclpy.init()

    node = Node("jaime_behaviour_tree")

    root = create_tree(node)

    tree = py_trees.trees.BehaviourTree(root)

    tree.setup(timeout=15)

    try:

        while rclpy.ok():

            tree.tick()

            rclpy.spin_once(
                node,
                timeout_sec=0.1
            )

    except KeyboardInterrupt:

        pass

    finally:

        tree.shutdown()

        node.destroy_node()

        rclpy.shutdown()


if __name__ == "__main__":

    main()