"""Inicia ambos servidores de Jaime con el mismo entorno Python."""

import subprocess
import sys
import time
from pathlib import Path


def configurar_adb():
    """Reinicia ADB, verifica la tablet y configura los puertos reverse."""

    """# 1. Reiniciar el servidor ADB
    print("\nReiniciando servidor ADB...", flush=True)

    subprocess.run(["adb", "kill-server"], check=True)
    time.sleep(4)

    subprocess.run(["adb", "start-server"], check=True)
    time.sleep(4)"""

    print("Servidor ADB iniciado correctamente.\n", flush=True)

    # 2. Verificar dispositivos Android
    print("Verificando dispositivos Android...", flush=True)

    subprocess.run(
        ["adb", "devices", "-l"],
        check=True
    )

    # 3. Configurar los puertos de la tablet hacia el computador
    puertos = [8765, 8080]

    for puerto in puertos:
        print(
            f"Configurando ADB reverse para el puerto {puerto}...",
            flush=True
        )

        subprocess.run(
            [
                "adb", "-d", "reverse",
                f"tcp:{puerto}", f"tcp:{puerto}"
            ],
            check=True
        )

    print("ADB configurado correctamente.\n", flush=True)


def main():
    carpeta = Path(__file__).resolve().parent
    procesos = []

    try:
        # 1. Reiniciar y configurar ADB
        configurar_adb()

        # 2. Iniciar ambos servidores Python
        for nombre in (
            "websocket_server.py",
            "webrtc_receiver_headless_con_visor.py"
        ):
            print(f"Iniciando {nombre}...", flush=True)

            procesos.append(
                subprocess.Popen(
                    [sys.executable, "-u", str(carpeta / nombre)],
                    cwd=carpeta
                )
            )

        print("\nAmbos servidores iniciados correctamente.", flush=True)
        print(
            "Abre Jaime en la tablet. "
            "Visor en el PC: http://127.0.0.1:8080/view",
            flush=True
        )
        print(
            "Deja esta ventana abierta. Ctrl+C detiene los servidores.\n",
            flush=True
        )

        # 3. Supervisar los procesos
        while True:
            for proceso in procesos:
                codigo = proceso.poll()

                if codigo is not None:
                    print(
                        "Un servidor terminó. Revisa el error mostrado arriba.",
                        flush=True
                    )
                    return codigo if codigo != 0 else 1

            time.sleep(0.5)

    except KeyboardInterrupt:
        print("\nDeteniendo servidores...", flush=True)
        return 0

    finally:
        # 4. Detener los servidores Python
        for proceso in procesos:
            if proceso.poll() is None:
                proceso.terminate()

        for proceso in procesos:
            try:
                proceso.wait(timeout=5)

            except subprocess.TimeoutExpired:
                proceso.kill()
                proceso.wait()

        print("Servidores detenidos.", flush=True)


if __name__ == "__main__":
    sys.exit(main())