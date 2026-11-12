import json # Para conectarse a la tablet
import urllib.request # Para conectarse a la tablet

import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_sensor_data # Para conectarse a la tablet
from sensor_msgs.msg import BatteryState
from kobuki_ros_interfaces.msg import SensorState

PANEL_URL = "http://127.0.0.1:8767/api/robot_battery" # Para conectarse a la tablet


class KobukiBatteryNode(Node):
    def __init__(self):
        super().__init__("kobuki_battery_node")

        self.datos_kobuki = {"present": False} # Para conectarse a la tablet

        # Publica en formato estándar de ROS 2
        self.pub = self.create_publisher(BatteryState, "/battery/kobuki", 10)

        # Se suscribe al tópico interno del driver de Kobuki
        self.sub = self.create_subscription(
            SensorState,
            "/sensors/core",
            self.cb_sensor_core,
            qos_profile_sensor_data, # Para conectarse a la tablet
            #10, # Si no se quiere conectar a la tablet
        )
        #Caso base:
        #self.get_logger().info("Monitoreando batería de Kobuki en /sensors/core...") 
        #Caso tablet: Envía la lectura al panel web cada 2 segundos sin bloquear el callback de 50 Hz
        self.timer = self.create_timer(2.0, self.enviar_al_panel)
        self.get_logger().info("Monitoreando batería de Kobuki y enviando al panel (:8767)...")

    def cb_sensor_core(self, core_msg: SensorState):
        msg = BatteryState()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "kobuki_battery_link"
        msg.present = True
        msg.power_supply_technology = BatteryState.POWER_SUPPLY_TECHNOLOGY_LION

        # 1. Voltaje: Kobuki lo entrega en decivoltios (ej. 165 -> 16.5 V)
        voltaje = core_msg.battery / 10.0
        msg.voltage = float(voltaje)
        cargando = core_msg.charger > 0

        # 2. Porcentaje estimado: la batería de Kobuki es Li-Ion 4S (13.2 V vacía - 16.8 V llena)
        porcentaje = max(0.0, min(1.0, (voltaje - 13.2) / (16.8 - 13.2)))
        msg.percentage = float(porcentaje)

        # 3. Estado de carga
        if cargando:
            msg.power_supply_status = BatteryState.POWER_SUPPLY_STATUS_CHARGING
        else:
            msg.power_supply_status = BatteryState.POWER_SUPPLY_STATUS_DISCHARGING

        self.pub.publish(msg)

        # Guarda la última lectura formateada para el panel web, para tablet
        self.datos_kobuki = {
            "present": True,
            "voltage": round(float(voltaje), 2),
            "percentage": round(float(porcentaje) * 100.0, 1),
            "charging": cargando,
        }

    def enviar_al_panel(self):
        if not self.datos_kobuki.get("present"):
            return

        payload = json.dumps({"kobuki": self.datos_kobuki}).encode("utf-8")
        req = urllib.request.Request(
            PANEL_URL,
            data=payload,
            headers={"Content-Type": "application/json"},
            method="POST",
        )
        try:
            with urllib.request.urlopen(req, timeout=0.2):
                pass
        except Exception:
            # Si jaime_panel.py aún no está levantado, evita que el nodo falle
            pass


def main(args=None):
    rclpy.init(args=args)
    node = KobukiBatteryNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()