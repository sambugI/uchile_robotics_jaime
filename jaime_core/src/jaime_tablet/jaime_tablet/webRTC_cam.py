import rclpy
import cv2
import requests
import numpy as np

from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge


class WebRTCCamera(Node):

    def __init__(self):
        super().__init__('webrtc_camera')

        # URL del endpoint HTTP del servidor WebRTC
        self.declare_parameter(
            'url',
            'http://127.0.0.1:8080/frame.jpg'
        )

        # Resolución de salida.
        # Si height = 0, se conserva la relación de aspecto.
        self.declare_parameter('width', 1000)
        self.declare_parameter('height', 0)

        # Frecuencia de consulta del endpoint
        self.declare_parameter('fps', 10.0)

        self.url = self.get_parameter('url').value
        self.width = self.get_parameter('width').value
        self.height = self.get_parameter('height').value
        fps = self.get_parameter('fps').value

        if fps <= 0:
            raise ValueError('El parámetro fps debe ser mayor que cero')

        # Publisher ROS 2
        self.publisher = self.create_publisher(
            Image,
            'image_raw',
            10
        )

        self.bridge = CvBridge()

        # Reutilizar la sesión HTTP
        self.session = requests.Session()

        # Contadores para medir el rendimiento
        self.frames_publicados = 0
        self.ultimo_reporte = self.get_clock().now()

        # Timer para consultar y publicar imágenes
        self.timer = self.create_timer(
            1.0 / fps,
            self.timer_callback
        )

        self.get_logger().info(
            f'Conectando con el servidor WebRTC: {self.url}'
        )
        self.get_logger().info(
            f'Tópico de salida: /image_raw | Frecuencia objetivo: {fps} FPS'
        )

    def timer_callback(self):
        try:
            # Obtener el último frame disponible en el servidor WebRTC
            response = self.session.get(
                self.url,
                timeout=0.5
            )

            response.raise_for_status()

            # Convertir los bytes JPEG a una imagen OpenCV
            img_arr = np.frombuffer(
                response.content,
                dtype=np.uint8
            )

            img = cv2.imdecode(
                img_arr,
                cv2.IMREAD_COLOR
            )

            if img is None:
                self.get_logger().warning(
                    'No se pudo decodificar el frame recibido'
                )
                return

            # Redimensionar si se ha solicitado
            if self.width > 0 and self.height > 0:
                img = cv2.resize(
                    img,
                    (self.width, self.height)
                )

            elif self.width > 0:
                alto_original, ancho_original = img.shape[:2]
                nuevo_alto = round(
                    alto_original * self.width / ancho_original
                )

                img = cv2.resize(
                    img,
                    (self.width, nuevo_alto)
                )

            # Convertir a mensaje ROS 2
            msg = self.bridge.cv2_to_imgmsg(
                img,
                encoding='bgr8'
            )

            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = 'android_camera'

            # Publicar imagen
            self.publisher.publish(msg)

            self.frames_publicados += 1

            # Reportar frecuencia de publicación cada 5 segundos
            ahora = self.get_clock().now()
            duracion = (
                ahora - self.ultimo_reporte
            ).nanoseconds / 1e9

            if duracion >= 5.0:
                fps_real = self.frames_publicados / duracion

                self.get_logger().info(
                    f'FPS publicados: {fps_real:.2f}'
                )

                self.frames_publicados = 0
                self.ultimo_reporte = ahora

        except requests.RequestException as e:
            self.get_logger().warning(
                f'Error HTTP al recibir imagen: {e}'
            )

    def destroy_node(self):
        self.session.close()
        super().destroy_node()


def main(args=None):
    rclpy.init(args=args)

    node = WebRTCCamera()

    try:
        rclpy.spin(node)

    except KeyboardInterrupt:
        pass

    finally:
        node.destroy_node()

        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()