#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from dynamixel_sdk import *  
from std_msgs.msg import Float64MultiArray, Header
import math 
import numpy as np
import yaml
from ament_index_python.packages import get_package_share_directory
import serial
from cobs import cobs
import time
import struct
import re

class EncoderHandler:
    def __init__(self, port='/dev/head_ino', baudrate=115200, timeout=0.5):
        self.ser = serial.Serial(port, baudrate, timeout=timeout)
        time.sleep(2)
        self.ser.reset_input_buffer()
        print(f"Puerto serial {port} abierto a {baudrate} baudios.")

    def get_angles(self):
        try:
            raw = self.ser.readline()   # espera la línea completa o hasta timeout
            if not raw:
                return None

            decoded = raw.decode("utf-8", errors="ignore").strip()

            if not decoded:
                return None
            if "Reading from" in decoded:
                return None

            values = re.findall(r'-?\d+\.\d+', decoded)
            if len(values) != 4:
                return None

            return [float(v) for v in values]

        except Exception as e:
            print("Serial parse error:", e)
            return None
class DynamixelCommander():
    def __init__(self, config_path="/config/params.yaml"):
        pkg_share = get_package_share_directory("jaime_manipulation")
        
        config_path = pkg_share + config_path
        with open(config_path, "r") as file:
            self.config = yaml.safe_load(file)

        # Configuración general
        self.PROTOCOL_VERSION = self.config["protocol_version"]
        self.BAUDRATE = self.config["baudrate"]
        self.DEVICE_NAME = self.config["device_name"]
        self.MOTORS = self.config["motors"]

        self.DXL_IDS = [motor["id"] for motor in self.MOTORS]

        self.ADDR_PRESENT_POSITION = 36
        self.ADDR_PRESENT_SPEED = 38

        # Direcciones de los RX-28, RX-64 y MX-106
        self.ADDR_TORQUE_ENABLE = 24
        self.ADDR_CW_ANGLE_LIMIT = 6
        self.ADDR_CCW_ANGLE_LIMIT = 8
        self.ADDR_GOAL_POS = 30
        self.ADDR_GOAL_SPEED = 32

        self.TORQUE_ENABLE = 1
        self.TORQUE_DISABLE = 0

        # Inicializa puerto y handler
        self.portHandler = PortHandler(self.DEVICE_NAME)
        self.packetHandler = PacketHandler(self.PROTOCOL_VERSION)

        if not self.portHandler.openPort():
            print("[ERROR] No se pudo abrir el puerto")
            exit()

        if not self.portHandler.setBaudRate(self.BAUDRATE):
            print("[ERROR] No se pudo establecer la velocidad de baudios")
            exit()

        # Configura motores en modo rueda
        for dxl_id in self.DXL_IDS:
            if dxl_id in [1,2]:
                # Quitar límites de ángulo => modo rueda
                self.packetHandler.write2ByteTxRx(self.portHandler, dxl_id, self.ADDR_CW_ANGLE_LIMIT, 0)
                self.packetHandler.write2ByteTxRx(self.portHandler, dxl_id, self.ADDR_CCW_ANGLE_LIMIT, 0)
                # Activar torque
                self.packetHandler.write1ByteTxRx(self.portHandler, dxl_id, self.ADDR_TORQUE_ENABLE, self.TORQUE_ENABLE)
            elif dxl_id == 3:
                # Activar torque
                self.packetHandler.write1ByteTxRx(self.portHandler, dxl_id, self.ADDR_TORQUE_ENABLE, self.TORQUE_ENABLE)
            else:
                # Activar torque
                self.packetHandler.write1ByteTxRx(self.portHandler, dxl_id, self.ADDR_TORQUE_ENABLE, self.TORQUE_DISABLE)

        print(f"[INFO] {len(self.DXL_IDS)} motores inicializados en modo rueda.")
        self.last_sent_velocities = None

    def get_joints_data(self):
        positions = []
        velocities = []
        for dxl_id in self.DXL_IDS:
            data, result, error = self.packetHandler.readTxRx(
                self.portHandler, dxl_id, self.ADDR_PRESENT_POSITION, 4)

            if result != COMM_SUCCESS or error != 0 or data is None or len(data) < 4:
                print(f"[WARN] Fallo al leer motor {dxl_id}")
                continue

            pos_raw = data[0] + (data[1] << 8)
            vel_raw = data[2] + (data[3] << 8)

            offset = 0
            for motor in self.MOTORS:
                if motor["id"] == dxl_id:
                    offset = motor["offset"]


            positions.append(offset - pos_raw)
            velocities.append(vel_raw)

        return positions, velocities

    def set_velocity(self, velocities):

            velocities = list(velocities)

            # ====================================================
            # NO reenviar si no cambió
            # ====================================================

            if velocities == self.last_sent_velocities:
                return

            self.last_sent_velocities = velocities.copy()

            print("[INFO] Enviando nuevas velocidades:", velocities)

            # ====================================================
            # Envío Dynamixel
            # ====================================================

            for dxl_id in self.DXL_IDS:

                if dxl_id in [1, 2]:

                    vel = int(velocities[dxl_id - 1])

                    if vel < 0:
                        v = min(-vel, 1023)
                        reg_val = 1024 + v
                    else:
                        reg_val = min(vel, 1023)

                    self.packetHandler.write2ByteTxRx(
                        self.portHandler,
                        dxl_id,
                        self.ADDR_GOAL_SPEED,
                        reg_val
                    )

                elif dxl_id == 3:

                    vel = int(velocities[dxl_id - 1])

                    if vel < 0:
                        v = min(-vel, 1023)
                        reg_val = 1024 + v
                    else:
                        reg_val = min(vel, 1023)

                    if vel == 0:

                        # no se puede enviar 0 en modo joint
                        self.packetHandler.write2ByteTxRx(
                            self.portHandler,
                            dxl_id,
                            self.ADDR_GOAL_SPEED,
                            1
                        )

                    elif vel < 0:

                        self.packetHandler.write2ByteTxRx(
                            self.portHandler,
                            dxl_id,
                            self.ADDR_GOAL_SPEED,
                            reg_val
                        )

                        self.packetHandler.write2ByteTxRx(
                            self.portHandler,
                            dxl_id,
                            self.ADDR_GOAL_POS,
                            750
                        )

                    else:

                        self.packetHandler.write2ByteTxRx(
                            self.portHandler,
                            dxl_id,
                            self.ADDR_GOAL_SPEED,
                            reg_val
                        )

                        self.packetHandler.write2ByteTxRx(
                            self.portHandler,
                            dxl_id,
                            self.ADDR_GOAL_POS,
                            1000
                        )


    def shutdown(self):
        for dxl_id in self.DXL_IDS:
            self.packetHandler.write1ByteTxRx(self.portHandler, dxl_id, self.ADDR_TORQUE_ENABLE, self.TORQUE_DISABLE)
        self.portHandler.closePort()
        print("[INFO] Puerto cerrado y torque desactivado.")




class DynamixelNode(Node):
    def __init__(self):
        super().__init__('dynamixel_node')

        # Crear publicador
        self.joint_pub = self.create_publisher(JointState, 'joint_states', 10)

        self.timer = self.create_timer(0.05, self.publish_joint_states)  

        self.move_timer = self.create_timer(0.1, self.move_joints)  

        # Subscriptor a velocidad deseada
        self.velocitie_sub = self.create_subscription(
            Float64MultiArray,
            'goal_vel',
            self.velocitie_callback,
            10
        )
        
        self.encoder = EncoderHandler()

        self.dynamixel = DynamixelCommander()

        self.mode = "speed"
        self.goal_position = None

        self.joints = [0,0,0,0,0]
        self.vel = [0,0,0]

        self.offsets = [0.01, -2.63, -1.0, -1.11, 2.6] # Se añadió offset para la tablet

        self.lower_limits = [0.0,0.0, 0.0, 0.0,-2.49]
        self.upper_limits = [0.6,0.5,0.56,0.36, 0.55]
        
    def publish_joint_states(self):

        joint_state_msg = JointState()
        joint_state_msg.header = Header()
        joint_state_msg.header.stamp = self.get_clock().now().to_msg()

        joint_state_msg.name = ['l3_to_l2', 'l4_to_l3', 'l5_to_l4',"l6_to_l5","l7_to_l6"]

        ang = self.encoder.get_angles()
        pos,vel = self.dynamixel.get_joints_data()

        resolution = 1023
        max_radians = math.radians(300)
        
        pos_raw = pos[2]
        
        pos_rad = ((pos_raw) / resolution) * max_radians
        if ang:
            # Se repitió el primer ángulo, debido a que el segundo encoder no está funcionando
            self.joints = [ang[0]-self.offsets[0], (ang[0]-self.offsets[0]), (ang[2]-self.offsets[2]),(ang[3]-self.offsets[3]), pos_rad + self.offsets[4]]

        joint_state_msg.position = self.joints
        joint_state_msg.velocity = []  # Dejar vacío si no se calcula
        joint_state_msg.effort = []    # Dejar vacío si no se mide/calcula
        
        # 4. Publicar el mensaje
        self.joint_pub.publish(joint_state_msg)

    def move_joints(self):
        raw_vel = np.array(self.vel) * 100
        vel = raw_vel.tolist()
        # Mapeo: cada comando de velocidad y sus joints asociados
        groups = [
            {"joints": [0, 1], "lower": [self.lower_limits[0], self.lower_limits[1]],
            "upper": [self.upper_limits[0], self.upper_limits[1]]},
            {"joints": [2, 3], "lower": [self.lower_limits[2], self.lower_limits[3]],
            "upper": [self.upper_limits[2], self.upper_limits[3]]},
            {"joints": [4], "lower": [None], "upper": [None]},  # solo encoder del motor
        ]

        for i in range(3):
            if i < 2:
                q1 = self.joints[groups[i]["joints"][0]]
                q2 = self.joints[groups[i]["joints"][1]]

                if vel[i] < 0:
                    if q1 <= groups[i]["lower"][0] or q2 <= groups[i]["lower"][1]:
                        print(i, "limite inferior alcanzado")
                        vel[i] = 0
                elif vel[i] > 0:
                    if q1 >= groups[i]["upper"][0] or q2 >= groups[i]["upper"][1]:
                        print(i, "limite superior alcanzado")
                        vel[i] = 0

            else:
                q = self.joints[4]
                if vel[i] < 0 and q <= self.lower_limits[4]:
                    print(i, "limite inferior alcanzado")
                    vel[i] = 0
                elif vel[i] > 0 and q >= self.upper_limits[4]:
                    print(i, "limite superior alcanzado")
                    vel[i] = 0

        self.dynamixel.set_velocity(vel)
         
    def velocitie_callback(self, msg: Float64MultiArray):
        if len(msg.data) != 3:
            self.get_logger().warn("Se esperaban exactamente 3 posiciones (en radianes)")
            return
        else:
            self.mode = "speed"
            self.vel = msg.data.tolist()
    def destroy_node(self):
        pass


def main(args=None):
    rclpy.init(args=args)
    node = DynamixelNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


main()
