import asyncio
import base64
import binascii
import json
import math
import time
import uuid

from websockets.asyncio.server import serve
from websockets.exceptions import ConnectionClosed


INTERVALO_REPORTE_ACELEROMETRO = 2.0
INTERVALO_REPORTE_GIROSCOPIO = 2.0
INTERVALO_REPORTE_ORIENTACION = 2.0
INTERVALO_REPORTE_CAMARA = 5.0
ACCIONES_PERMITIDAS = {"status", "camera_start", "camera_stop"}
tableta_activa = None
ordenes_pendientes = {}


async def enviar_ack(websocket, tipo, sensor=None, value=None):
    respuesta = {
        "type": "ack",
        "received_type": tipo,
        "timestamp": int(time.time() * 1000),
    }

    if sensor is not None:
        respuesta["sensor"] = sensor

    if value is not None:
        respuesta["value"] = value

    await websocket.send(json.dumps(respuesta))


async def recibir_mensajes(websocket):
    global tableta_activa
    tableta_activa = websocket
    print("Tablet conectada")

    ultimo_reporte_acelerometro = 0.0
    ultimo_reporte_giroscopio = 0.0
    ultimo_reporte_orientacion = 0.0
    ultima_bateria = None
    muestras_acelerometro = 0
    muestras_giroscopio = 0
    muestras_orientacion = 0
    frames_camara = 0
    frames_intervalo = 0
    bytes_jpeg_intervalo = 0
    bytes_ws_intervalo = 0
    inicio_intervalo = time.monotonic()

    try:
        async for mensaje in websocket:
            try:
                data = json.loads(mensaje)
            except json.JSONDecodeError:
                print("Mensaje JSON inválido")
                continue
            if not isinstance(data, dict):
                print("Mensaje JSON inválido")
                continue

            tipo = data.get("type")

            if tipo == "command_result":
                identificador = data.get("id")
                respuesta_pendiente = (
                    ordenes_pendientes.pop(identificador, None)
                    if isinstance(identificador, str) else None
                )
                if respuesta_pendiente is not None and not respuesta_pendiente.done():
                    respuesta_pendiente.set_result(data)
                continue

            if tipo == "ping":
                respuesta = {
                    "type": "pong",
                    "timestamp": data.get("timestamp"),
                    "server_timestamp": int(time.time() * 1000),
                }

                await websocket.send(json.dumps(respuesta))
                continue

            # Se conserva la vía de cámara JPEG por WebSocket para compatibilidad.
            if tipo == "camera_frame":
                imagen_base64 = data.get("data", "")
                if not isinstance(imagen_base64, str):
                    print("Frame de cámara inválido")
                    continue
                if "," in imagen_base64:
                    imagen_base64 = imagen_base64.split(",", 1)[1]

                try:
                    imagen_bytes = base64.b64decode(imagen_base64, validate=True)
                    with open("latest_frame.jpg", "wb") as archivo:
                        archivo.write(imagen_bytes)
                except (binascii.Error, OSError, ValueError) as error:
                    print("Error procesando frame:", error)
                    continue

                frames_camara += 1
                frames_intervalo += 1
                bytes_jpeg_intervalo += len(imagen_bytes)
                bytes_ws_intervalo += len(mensaje.encode("utf-8"))
                ahora = time.monotonic()
                duracion = ahora - inicio_intervalo

                if duracion >= INTERVALO_REPORTE_CAMARA:
                    print(
                        "\n----- RENDIMIENTO CÁMARA -----\n"
                        f"Frames totales: {frames_camara}\n"
                        f"FPS recibidos: {frames_intervalo / duracion:.2f}\n"
                        "Tamaño promedio JPEG: "
                        f"{bytes_jpeg_intervalo / frames_intervalo / 1024:.1f} KB\n"
                        f"Datos JPEG: {bytes_jpeg_intervalo * 8 / duracion / 1_000_000:.3f} Mbps\n"
                        f"Tráfico WebSocket: {bytes_ws_intervalo * 8 / duracion / 1_000_000:.3f} Mbps\n"
                        "------------------------------\n"
                    )
                    inicio_intervalo = ahora
                    frames_intervalo = 0
                    bytes_jpeg_intervalo = 0
                    bytes_ws_intervalo = 0
                continue

            if tipo == "telemetry":
                sensor = data.get("sensor")
                valores = data.get("data") or {}

                if sensor == "battery":
                    nivel = valores.get("level")
                    cargando = bool(valores.get("charging", False))
                    fuente = valores.get("power_source", "none")

                    estado_bateria = (nivel, cargando, fuente)

                    if estado_bateria != ultima_bateria:
                        estado_carga = "cargando" if cargando else "sin cargar"

                        print(
                            f"Batería | {nivel}% | "
                            f"{estado_carga} | fuente: {fuente}"
                        )

                        ultima_bateria = estado_bateria

                    await enviar_ack(websocket, tipo, sensor=sensor)
                    continue

                if sensor == "accelerometer":
                    try:
                        x = float(valores.get("x", 0.0))
                        y = float(valores.get("y", 0.0))
                        z = float(valores.get("z", 0.0))
                    except (TypeError, ValueError):
                        print("Datos inválidos del acelerómetro")
                        continue

                    muestras_acelerometro += 1
                    ahora = time.monotonic()

                    if (
                        ahora - ultimo_reporte_acelerometro
                        >= INTERVALO_REPORTE_ACELEROMETRO
                    ):
                        magnitud = math.sqrt(x * x + y * y + z * z)

                        print(
                            "Acelerómetro | "
                            f"X: {x:7.3f} | "
                            f"Y: {y:7.3f} | "
                            f"Z: {z:7.3f} | "
                            f"Magnitud: {magnitud:7.3f} m/s² | "
                            f"Muestras: {muestras_acelerometro}"
                        )

                        ultimo_reporte_acelerometro = ahora

                    await enviar_ack(websocket, tipo, sensor=sensor)
                    continue

                if sensor == "gyroscope":
                    try:
                        x = float(valores["x"])
                        y = float(valores["y"])
                        z = float(valores["z"])
                    except (KeyError, TypeError, ValueError):
                        print("Datos inválidos del giroscopio")
                        continue

                    muestras_giroscopio += 1
                    ahora = time.monotonic()

                    if ahora - ultimo_reporte_giroscopio >= INTERVALO_REPORTE_GIROSCOPIO:
                        print(
                            "Giroscopio | "
                            f"X: {x:7.3f} | Y: {y:7.3f} | Z: {z:7.3f} rad/s | "
                            f"Muestras: {muestras_giroscopio}"
                        )
                        ultimo_reporte_giroscopio = ahora

                    await enviar_ack(websocket, tipo, sensor=sensor)
                    continue

                if sensor == "orientation":
                    try:
                        azimuth = float(valores["azimuth"])
                        pitch = float(valores["pitch"])
                        roll = float(valores["roll"])
                    except (KeyError, TypeError, ValueError):
                        print("Datos inválidos de orientación")
                        continue

                    muestras_orientacion += 1
                    ahora = time.monotonic()

                    if ahora - ultimo_reporte_orientacion >= INTERVALO_REPORTE_ORIENTACION:
                        print(
                            "Orientación | "
                            f"Azimut: {azimuth:6.1f}° | "
                            f"Inclinación: {pitch:6.1f}° | "
                            f"Giro lateral: {roll:6.1f}° | "
                            f"Muestras: {muestras_orientacion}"
                        )
                        ultimo_reporte_orientacion = ahora

                    await enviar_ack(websocket, tipo, sensor=sensor)
                    continue

                if sensor == "sensor_status":
                    print(
                        "Sensores disponibles | "
                        f"Acelerómetro: {bool(valores.get('accelerometer'))} | "
                        f"Giroscopio: {bool(valores.get('gyroscope'))} | "
                        f"Orientación: {bool(valores.get('orientation'))}"
                    )
                    await enviar_ack(websocket, tipo, sensor=sensor)
                    continue

                print("Telemetría desconocida:", data)
                await enviar_ack(websocket, tipo, sensor=sensor)
                continue

            print("Mensaje recibido:", data)

            await enviar_ack(
                websocket,
                tipo,
                value=data.get("value"),
            )

    except ConnectionClosed:
        print("Tablet desconectada")
    except Exception as error:
        print("Conexión cerrada:", error)
    finally:
        if tableta_activa is websocket:
            tableta_activa = None
            for futuro in ordenes_pendientes.values():
                if not futuro.done():
                    futuro.set_result({"ok": False, "error": "La tablet se desconectó"})


async def manejar_control(reader, writer):
    """Acepta un comando JSON por conexión, solo desde este PC."""
    respuesta = {"ok": False, "error": "Comando inválido"}
    identificador = None
    try:
        linea = await asyncio.wait_for(reader.readline(), timeout=5)
        if len(linea) > 4096:
            raise ValueError("Comando demasiado largo")
        solicitud = json.loads(linea)
        accion = solicitud.get("action")
        if accion not in ACCIONES_PERMITIDAS:
            raise ValueError("Acción no admitida")
        if tableta_activa is None:
            raise ValueError("La tablet no está conectada")

        identificador = uuid.uuid4().hex
        respuesta_pendiente = asyncio.get_running_loop().create_future()
        ordenes_pendientes[identificador] = respuesta_pendiente
        await tableta_activa.send(json.dumps({
            "type": "command", "id": identificador, "action": accion
        }))
        respuesta = await asyncio.wait_for(respuesta_pendiente, timeout=15)
        print("Respuesta de la tablet al PC:", accion, respuesta.get("ok"))
    except (ValueError, json.JSONDecodeError, asyncio.TimeoutError) as error:
        respuesta = {"ok": False, "error": str(error) or "Tablet sin respuesta"}
    except Exception as error:
        respuesta = {"ok": False, "error": str(error)}
    finally:
        if identificador is not None:
            ordenes_pendientes.pop(identificador, None)
        writer.write((json.dumps(respuesta, ensure_ascii=False) + "\n").encode())
        try:
            await writer.drain()
        finally:
            writer.close()
            await writer.wait_closed()


async def main():
    async with serve(
        recibir_mensajes,
        "0.0.0.0",
        8765,
        max_size=10_000_000,
    ):
        control = await asyncio.start_server(manejar_control, "127.0.0.1", 8766)
        print("Servidor WebSocket iniciado")
        print("Esperando conexión en puerto 8765...")
        print("Control local disponible en 127.0.0.1:8766")

        async with control:
            await asyncio.get_running_loop().create_future()


if __name__ == "__main__":
    try:
        asyncio.run(main())
    except KeyboardInterrupt:
        print("\nServidor WebSocket detenido")
