import serial
import time
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import BatteryState

class JaimeBattery(Node):
    def __init__(self):
        super().__init__("jaime_battery_node")
        
        self.port_name = "/dev/battery_bms"
        self.ser = None

        self.pub = self.create_publisher(BatteryState, "battery_status", 10)
        self.timer = self.create_timer(1.0, self.publicador)

    def abrir_puerto(self):
        if self.ser is not None and self.ser.is_open:
            return True
        try:
            self.ser = serial.Serial(
                port=self.port_name,
                baudrate=9600,
                timeout=1.0
            )
            self.get_logger().info(f"¡Puerto serie {self.port_name} abierto exitosamente!")
            return True
        except Exception as e:
            self.ser = None
            self.get_logger().error(f"Fallo al abrir puerto {self.port_name}: {e}")
            return False

    def leer_bms_raw(self):
        if not self.abrir_puerto():
            return None

        # Trama estándar de consulta de información básica para BMS JBD:
        # DD A5 03 00 FF FD 77
        cmd = bytes([0xDD, 0xA5, 0x03, 0x00, 0xFF, 0xFD, 0x77])
        
        try:
            self.ser.reset_input_buffer()
            self.ser.write(cmd)
            time.sleep(0.15)  # Retardo crucial para permitir la respuesta del microcontrolador JBD
            
            response = self.ser.read_all()

            # La respuesta básica válida de JBD BMS empieza por 0xDD 0x03 y tiene al menos 20 bytes
            if len(response) >= 20 and response[0] == 0xDD and response[1] == 0x03:
                return response
            else:
                self.get_logger().warn(f"Trama corrupta o incompleta ({len(response)} bytes recibidos)")
                return None
        except Exception as e:
            self.get_logger().error(f"Error de E/S en puerto serie: {e}")
            if self.ser:
                self.ser.close()
            self.ser = None
            return None

    def publicador(self):
        raw_data = self.leer_bms_raw()
        if raw_data is None:
            return

        try:
            # Desempaquetado manual del protocolo JBD BMS:
            # Bytes 4 y 5: Voltaje total en decivoltios (big-endian) -> dividir entre 100 para Voltios
            total_voltage = ((raw_data[4] << 8) | raw_data[5]) / 100.0

            # Bytes 6 y 7: Corriente en deciamperios (con signo / complemento a dos)
            raw_current = (raw_data[6] << 8) | raw_data[7]
            if raw_current > 32767:
                raw_current -= 65536
            current = raw_current / 100.0

            # Bytes 8 y 9: Capacidad restante en deci-Ah -> dividir entre 100
            residual_capacity = ((raw_data[8] << 8) | raw_data[9]) / 100.0

            # Byte 23: Porcentaje de carga (SOC 0-100%)
            rsoc = raw_data[23] if len(raw_data) > 23 else 0

            # Construir mensaje ROS 2
            msg = BatteryState()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = "battery_link"

            msg.voltage = float(total_voltage)
            msg.current = float(current)
            msg.capacity = float(residual_capacity)
            msg.percentage = float(rsoc) / 100.0

            self.pub.publish(msg)
            self.get_logger().info(
                f"BMS -> Voltaje: {msg.voltage:.2f}V | Corriente: {msg.current:.2f}A | SOC: {rsoc}%"
            )

        except Exception as e:
            self.get_logger().error(f"Fallo al decodificar trama binaria: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = JaimeBattery()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if node.ser and node.ser.is_open:
            node.ser.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()