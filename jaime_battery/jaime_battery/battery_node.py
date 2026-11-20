import rclpy
from rclpy.node import Node
from sensor_msgs.msg import BatteryState
from jaime_battery.jbd_translator import BMS

class JaimeBattery(Node):
    def __init__(self):
        super().__init__("jaime_battery_node")

        self.bms = BMS()
        self.pub = self.create_publisher(BatteryState, "battery_status", 10)
        self.timer = self.create_timer(1.0, self.publicador)

    def publicador(self):
        msg = BatteryState()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "battery_link"

        msg.voltage = float(self.bms.voltage)
        msg.current = float(self.bms.current)
        msg.temperature = float(self.bms.temp)
        msg.capacity = float(self.bms.residual_capacity)
        msg.design_capacity = float(self.bms.total_capacity)
        msg.percentage = float(self.bms.percentage)

        self.pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = JaimeBattery()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        if node.bms.port and node.bms.port.is_open:
            node.bms.port.close()
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()