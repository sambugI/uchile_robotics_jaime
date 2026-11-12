#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist
from dynamixel_sdk import PortHandler, PacketHandler

DEVICENAME = '/dev/dynamixel'
BAUDRATE = 57600
PROTOCOL_VERSION = 1.0

# Registros Dynamixel AX/MX (Protocolo 1.0)
ADDR_CW_ANGLE_LIMIT = 6
ADDR_CCW_ANGLE_LIMIT = 8
ADDR_TORQUE_ENABLE = 24
ADDR_GOAL_POSITION = 30
ADDR_MOVING_SPEED = 32
DXL_SPEED = 200

class QuickControl(Node):
    def __init__(self):
        super().__init__('quick_control_node')
        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel_joy', 10)
        self.joy_sub = self.create_subscription(Joy, 'joy', self.joy_callback, 10)

        self.port_handler = PortHandler(DEVICENAME)
        self.packet_handler = PacketHandler(PROTOCOL_VERSION)

        self.last_speed = {1: 0, 2: 0}
        
        # Parámetros de Posición para el Motor 3 (Modo Joint)
        self.target_pos_3 = 512       # Posición central inicial (0 - 1023, ~150°)
        self.pos_step = 8             # Velocidad/paso de incremento por evento del dpad
        self.min_pos_3 = 0            # Límite de posición inferior
        self.max_pos_3 = 1023         # Límite de posición superior
        self.last_pos_3 = -1          # Evita escrituras redundantes en el bus serial

        self.dxl_ok = False

        if self.port_handler.openPort() and self.port_handler.setBaudRate(BAUDRATE):
            self.get_logger().info(f"Conectado a Dynamixels en {DEVICENAME}")
            self.dxl_ok = True
            
            # --- MOTORES 1 y 2: Modo Rotación Continua (Wheel Mode) ---
            for dxl_id in [1, 2]:
                self.packet_handler.write2ByteTxRx(self.port_handler, dxl_id, ADDR_CW_ANGLE_LIMIT, 0)
                self.packet_handler.write2ByteTxRx(self.port_handler, dxl_id, ADDR_CCW_ANGLE_LIMIT, 0)
                self.packet_handler.write1ByteTxRx(self.port_handler, dxl_id, ADDR_TORQUE_ENABLE, 1)

            # --- MOTOR 3: Modo Posición (Joint Mode) ---
            # CW=0 y CCW=1023 activa el rango angular normal de 0° a 300°
            self.packet_handler.write2ByteTxRx(self.port_handler, 3, ADDR_CW_ANGLE_LIMIT, self.min_pos_3)
            self.packet_handler.write2ByteTxRx(self.port_handler, 3, ADDR_CCW_ANGLE_LIMIT, self.max_pos_3)
            self.packet_handler.write1ByteTxRx(self.port_handler, 3, ADDR_TORQUE_ENABLE, 1)
            
            # Establecer velocidad fija de movimiento para el motor 3
            self.packet_handler.write2ByteTxRx(self.port_handler, 3, ADDR_MOVING_SPEED, DXL_SPEED)
            
            # Mover el Motor 3 a su posición inicial
            self.set_position(3, self.target_pos_3)

    def set_velocity(self, dxl_id, speed):
        """Aplica velocidad para los motores 1 y 2 en modo rueda."""
        if self.dxl_ok and self.last_speed.get(dxl_id) != speed:
            val = 1024 + min(int(abs(speed)), 1023) if speed < 0 else min(int(speed), 1023)
            self.packet_handler.write2ByteTxRx(self.port_handler, dxl_id, ADDR_MOVING_SPEED, val)
            self.last_speed[dxl_id] = speed

    def set_position(self, dxl_id, position):
        """Aplica la posición objetivo (0 a 1023) para el Motor 3."""
        position_int = int(max(self.min_pos_3, min(self.max_pos_3, position)))
        if self.dxl_ok and self.last_pos_3 != position_int:
            self.packet_handler.write2ByteTxRx(self.port_handler, dxl_id, ADDR_GOAL_POSITION, position_int)
            self.last_pos_3 = position_int

    def joy_callback(self, msg: Joy):
        btn_a = msg.buttons[0] if len(msg.buttons) > 0 else 0
        btn_b = msg.buttons[1] if len(msg.buttons) > 1 else 0
        btn_x = msg.buttons[2] if len(msg.buttons) > 2 else 0
        btn_y = msg.buttons[3] if len(msg.buttons) > 3 else 0
        dpad_vert = msg.axes[7] if len(msg.axes) > 7 else (msg.axes[5] if len(msg.axes) > 5 else 0.0)

        # 1. Control de la Base Kobuki
        twist = Twist()
        if len(msg.axes) > 1:
            twist.linear.x = msg.axes[1] * 0.3
            twist.angular.z = msg.axes[0] * 0.8
        self.cmd_vel_pub.publish(twist)

        # 2. Control de Velocidad (Motores 1 y 2 en modo Rueda)
        speed_1 = DXL_SPEED if btn_y else (-DXL_SPEED if btn_x else 0)
        speed_2 = DXL_SPEED if btn_b else (-DXL_SPEED if btn_a else 0)
        self.set_velocity(1, speed_1)
        self.set_velocity(2, speed_2)

        # 3. Control de Posición (Motor 3 con Flechas Arriba / Abajo)
        if dpad_vert > 0.5:
            # Flecha Arriba -> Incrementar posición
            self.target_pos_3 += self.pos_step
        elif dpad_vert < -0.5:
            # Flecha Abajo -> Decrementar posición
            self.target_pos_3 -= self.pos_step

        self.set_position(3, self.target_pos_3)

    def destroy_node(self):
        if self.dxl_ok:
            for dxl_id in [1, 2]:
                self.set_velocity(dxl_id, 0)
            self.port_handler.closePort()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = QuickControl()
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