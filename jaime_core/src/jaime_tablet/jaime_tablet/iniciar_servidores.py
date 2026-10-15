"""Inicia ambos servidores de Jaime con el mismo entorno Python."""
import subprocess
import sys
import time
from pathlib import Path
import subprocess

def configurar_adb():
    """Verifica la tablet y configura los puertos ADB reverse."""

    print("\nVerificando dispositivos Android...", flush=True)

    # Mostrar dispositivos conectados
    subprocess.run(
        ["adb", "devices", "-l"],
        check=True
    )

    # Configurar los puertos de la tablet hacia el computador
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
        # 1. Configurar ADB antes de iniciar los servidores
        configurar_adb()
        for nombre in ("websocket_server.py", "webrtc_receiver_headless_con_visor.py"):
            procesos.append(subprocess.Popen(
                [sys.executable, "-u", str(carpeta / nombre)], cwd=carpeta
            ))
        print("\nAbre Jaime en la tablet. Visor en el PC: http://127.0.0.1:8080/view", flush=True)
        print("Deja esta ventana abierta. Ctrl+C detiene los servidores.\n", flush=True)
        while True:
            for proceso in procesos:
                codigo = proceso.poll()
                if codigo is not None:
                    print("Un servidor termino. Revisa el error mostrado arriba.", flush=True)
                    return codigo if codigo != 0 else 1
            time.sleep(0.5)
    except KeyboardInterrupt:
        return 0
    finally:
        for proceso in procesos:
            if proceso.poll() is None:
                proceso.terminate()
        for proceso in procesos:
            try:
                proceso.wait(timeout=5)
            except subprocess.TimeoutExpired:
                proceso.kill()
                proceso.wait()


if __name__ == "__main__":
    sys.exit(main())
