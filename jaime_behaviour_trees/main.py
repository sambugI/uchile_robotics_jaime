import rclpy
import py_trees

from mission_tree import create_tree


def main():

    rclpy.init()

    root = create_tree()

    tree = py_trees.trees.BehaviourTree(root)

    tree.setup(timeout=15)

    try:

        tree.tick_tock(
            period_ms=100
        )

        rclpy.spin(tree.node)

    except KeyboardInterrupt:
        pass

    finally:

        tree.shutdown()

        rclpy.shutdown()


if __name__ == "__main__":
    main()