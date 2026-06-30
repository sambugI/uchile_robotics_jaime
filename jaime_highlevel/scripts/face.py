import cv2
import bleedfacedetector
import time

import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray


class FaceDetectorNode(Node):

    def __init__(self):
        super().__init__('face_detector_node')

        # Publicador
        self.pub_face = self.create_publisher(
            Float64MultiArray,
            'face_position',
            10
        )

        # Timer a 10 Hz
        self.timer = self.create_timer(0.01, self.timer_callback)

        # Cámara
        self.cap = cv2.VideoCapture("/dev/video2")

        self.fps = 0.0


    def timer_callback(self):
        start_time = time.time()

        ret, img = self.cap.read()
        if not ret:
            self.get_logger().warn("No se pudo leer imagen de la cámara")
            return

        img = cv2.flip(img, 1)

        # Detección
        faces = bleedfacedetector.ssd_detect(img)

        msg = Float64MultiArray()

        if faces == []:
            # Publica valores indicando ausencia
            msg.data = [-1.0, -1.0]
        else:
            (x, y, w, h) = faces[0]

            # Centro del bounding box
            cx = x + w/2
            cy = y + h/2

            msg.data = [float(cx), float(cy)]

            # Dibujar
            cv2.rectangle(img, (x,y), (x+w, y+h), (0,0,255), 2)
            cv2.putText(img, 'Face Detected',
                        (x, y+h+15),
                        cv2.FONT_HERSHEY_SIMPLEX,
                        0.5,
                        (0,0,255),
                        2,
                        cv2.LINE_AA)

        # Publicar mensaje
        self.pub_face.publish(msg)

        # FPS
        self.fps = 1.0 / (time.time() - start_time)
        cv2.putText(img, f"FPS: {self.fps:.2f}", (20, 20),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255))

        # Mostrar imagen
        cv2.imshow("img", img)
        cv2.waitKey(1)


    def destroy_node(self):
        self.cap.release()
        cv2.destroyAllWindows()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)
    node = FaceDetectorNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
