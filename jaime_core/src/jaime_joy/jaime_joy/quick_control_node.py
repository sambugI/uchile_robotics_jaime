#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist
from dynamixel_sdk import PortHandler, PacketHandler

DEVICENAME = '/dev/dynamixel'
BAUDRATE = 57600
PROTOCOL_VERSION = 1.0

ADDR_CW_ANGLE_LIMIT = 6
ADDR_CCW_ANGLE_LIMIT = 8
ADDR_TORQUE_ENABLE = 24
ADDR_MOVING_SPEED = 32
DXL_SPEED = 200

class QuickControl(Node):
    def __init__(self):
        super().__init__('quick_control_node')
        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel_joy', 10)
        self.joy_sub = self.create_subscription(Joy, 'joy', self.joy_callback, 10)

        self.port_handler = PortHandler(DEVICENAME)
        self.packet_handler = PacketHandler(PROTOCOL_VERSION)

        self.last_speed = {1: 0, 2: 0, 3: 0}
        self.dxl_ok = False

        if self.port_handler.openPort() and self.port_handler.setBaudRate(BAUDRATE):
            self.get_logger().info(f"Conectado a Dynamixels en {DEVICENAME}")
            self.dxl_ok = True
            for dxl_id in [1, 2, 3]:
                self.packet_handler.write2ByteTxRx(self.port_handler, dxl_id, ADDR_CW_ANGLE_LIMIT, 0)
                self.packet_handler.write2ByteTxRx(self.port_handler, dxl_id, ADDR_CCW_ANGLE_LIMIT, 0)
                self.packet_handler.write1ByteTxRx(self.port_handler, dxl_id, ADDR_TORQUE_ENABLE, 1)

    def set_velocity(self, dxl_id, speed):
        if self.dxl_ok and self.last_speed.get(dxl_id) != speed:
            val = 1024 + min(int(abs(speed)), 1023) if speed < 0 else min(int(speed), 1023)
            self.packet_handler.write2ByteTxRx(self.port_handler, dxl_id, ADDR_MOVING_SPEED, val)
            self.last_speed[dxl_id] = speed

    def joy_callback(self, msg: Joy):
        btn_a = msg.buttons[0] if len(msg.buttons) > 0 else 0
        btn_b = msg.buttons[1] if len(msg.buttons) > 1 else 0
        btn_x = msg.buttons[2] if len(msg.buttons) > 2 else 0
        btn_y = msg.buttons[3] if len(msg.buttons) > 3 else 0
        dpad_vert = msg.axes[7] if len(msg.axes) > 7 else (msg.axes[5] if len(msg.axes) > 5 else 0.0)

        twist = Twist()
        if len(msg.axes) > 1:
            twist.linear.x = msg.axes[1] * 0.3
            twist.angular.z = msg.axes[0] * 0.8
        self.cmd_vel_pub.publish(twist)

        speed_1 = DXL_SPEED if btn_y else (-DXL_SPEED if btn_x else 0)
        speed_2 = DXL_SPEED if btn_b else (-DXL_SPEED if btn_a else 0)
        speed_3 = DXL_SPEED if dpad_vert > 0.5 else (-DXL_SPEED if dpad_vert < -0.5 else 0)

        self.set_velocity(1, speed_1)
        self.set_velocity(2, speed_2)
        self.set_velocity(3, speed_3)

    def destroy_node(self):
        if self.dxl_ok:
            for dxl_id in [1, 2, 3]:
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
