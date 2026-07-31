#!/usr/bin/env python3

import time
from dynamixel_sdk import *

DEVICE_NAME = "/dev/dynamixel"
BAUDRATE = 57600
PROTOCOL_VERSION = 1.0

DXL_ID = 2

ADDR_TORQUE_ENABLE = 24
ADDR_CW_ANGLE_LIMIT = 6
ADDR_CCW_ANGLE_LIMIT = 8
ADDR_GOAL_SPEED = 32
ADDR_PRESENT_POSITION = 36
ADDR_PRESENT_SPEED = 38

TORQUE_ENABLE = 1
TORQUE_DISABLE = 0

portHandler = PortHandler(DEVICE_NAME)
packetHandler = PacketHandler(PROTOCOL_VERSION)

if not portHandler.openPort():
    raise RuntimeError("No se pudo abrir el puerto")

if not portHandler.setBaudRate(BAUDRATE):
    raise RuntimeError("No se pudo configurar el baudrate")

# Modo rueda
packetHandler.write2ByteTxRx(portHandler, DXL_ID, ADDR_CW_ANGLE_LIMIT, 0)
packetHandler.write2ByteTxRx(portHandler, DXL_ID, ADDR_CCW_ANGLE_LIMIT, 0)

packetHandler.write1ByteTxRx(
    portHandler,
    DXL_ID,
    ADDR_TORQUE_ENABLE,
    TORQUE_ENABLE
)

print("Motor 2: velocidad -50")

packetHandler.write2ByteTxRx(
    portHandler,
    DXL_ID,
    ADDR_GOAL_SPEED,
    1024 + 50
)

start = time.time()

fail_count = 0
success_count = 0

while time.time() - start < 3.0:

    data, result, error = packetHandler.readTxRx(
        portHandler,
        DXL_ID,
        ADDR_PRESENT_POSITION,
        4
    )

    if result != COMM_SUCCESS or error != 0 or data is None or len(data) < 4:
        fail_count += 1

        print(
            f"[FALLO #{fail_count}] "
            f"Comm={result} "
            f"({packetHandler.getTxRxResult(result)}) "
            f"Error={error}"
        )

    else:
        success_count += 1

        pos = data[0] + (data[1] << 8)
        vel = data[2] + (data[3] << 8)

        print(
            f"[OK #{success_count}] "
            f"Pos={pos:4d} "
            f"Vel={vel:4d}"
        )

    time.sleep(0.02)      # 50 Hz

print("\nDeteniendo motor...")

packetHandler.write2ByteTxRx(
    portHandler,
    DXL_ID,
    ADDR_GOAL_SPEED,
    0
)

packetHandler.write1ByteTxRx(
    portHandler,
    DXL_ID,
    ADDR_TORQUE_ENABLE,
    TORQUE_DISABLE
)

portHandler.closePort()

print("\nResumen")
print(f"Lecturas correctas : {success_count}")
print(f"Lecturas fallidas  : {fail_count}")