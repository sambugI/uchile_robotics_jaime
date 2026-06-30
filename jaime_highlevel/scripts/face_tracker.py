import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray
import numpy as np

class FaceListener(Node):

    def __init__(self):
        super().__init__('face_listener')

        # Suscriptor al tópico que publicas
        self.subscription = self.create_subscription(
            Float64MultiArray,
            'face_position',
            self.callback_face,
            10
        )   

        # Publicador
        self.cmd_pub = self.create_publisher(
            Float64MultiArray,
            'cmd',
            10
        )

        # Timer a 10 Hz
        self.timer = self.create_timer(0.01, self.tracker_callback)


        self.pos = [-1,-1]

    def callback_face(self, msg):
        data = msg.data

        if len(data) != 2:
            self.get_logger().warn("Mensaje inválido recibido")
            return

        self.pos = data

    def tracker_callback(self):
        error = None
        msg = Float64MultiArray()
        if self.pos[1] != -1 :
            error = 240 - self.pos[1]
            if abs(error) < 0: # se debería cambiar esto a un valor como 5, porque nunca se va a llegar a hacer.
                error = 0

            vel = 0.01* error
            vel = np.clip(vel,-2,2)
            cmd = [0,0,-vel,0,0,0]
            print(cmd)
            msg.data = cmd
        else:
            msg.data = [0,0,0,0,0,0]

        self.cmd_pub.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = FaceListener()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
