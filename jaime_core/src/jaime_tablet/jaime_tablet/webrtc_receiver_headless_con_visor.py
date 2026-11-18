"""Receptor WebRTC de Jaime con visor de cámara de solo lectura por LAN."""

import asyncio
import io
import time

from aiohttp import web
from aiortc import RTCPeerConnection, RTCSessionDescription


pcs = set()
ultimo_jpeg = None
instante_jpeg = 0.0
intervalo_jpeg = 0.2  # Hasta cinco imágenes por segundo para el visor LAN.


def comprimir_frame(frame):
    """La conversión JPEG se realiza fuera del hilo de asyncio."""
    salida = io.BytesIO()
    frame.to_image().save(salida, format="JPEG", quality=70)
    return salida.getvalue()


async def recibir_video(track):
    global ultimo_jpeg, instante_jpeg
    frames_totales = 0
    frames_intervalo = 0
    inicio_total = time.monotonic()
    inicio_intervalo = inicio_total
    print("Comenzando a recibir video...", flush=True)
    try:
        while True:
            frame = await track.recv()
            # Conserva la preferencia por el frame más reciente de la versión visual.
            cola = getattr(track, "_queue", None)
            if cola is not None:
                while not cola.empty():
                    reciente = cola.get_nowait()
                    if reciente is not None:
                        frame = reciente
            frames_totales += 1
            frames_intervalo += 1
            ahora = time.monotonic()
            if ahora - instante_jpeg >= intervalo_jpeg:
                try:
                    nuevo_jpeg = await asyncio.to_thread(comprimir_frame, frame)
                    ultimo_jpeg = nuevo_jpeg
                    instante_jpeg = time.monotonic()
                except Exception as error:
                    print("No se pudo preparar la imagen para el visor:", error, flush=True)
            duracion = ahora - inicio_intervalo
            if duracion >= 2:
                print(
                    f"WebRTC OK | FPS: {frames_intervalo / duracion:.1f} | "
                    f"Frames: {frames_totales} | "
                    f"Duración: {ahora - inicio_total:.1f} s | "
                    f"Resolución: {frame.width}x{frame.height}",
                    flush=True,
                )
                frames_intervalo = 0
                inicio_intervalo = ahora
    except asyncio.CancelledError:
        raise
    except Exception as error:
        print("Video finalizado:", error, flush=True)


async def visor(request):
    return web.Response(
        text="""<!doctype html>
<html lang="es"><head><meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Cámara de Jaime</title>
<style>
html,body{margin:0;min-height:100%;background:#0b1522;color:#f7fafc;
font-family:system-ui,sans-serif} main{max-width:920px;margin:28px auto;padding:0 16px}
h1{font-size:24px}img{display:block;max-width:100%;max-height:80vh;margin:auto;
background:#05080d;border-radius:12px}p{color:#a9b6c7}
</style></head><body><main><h1>Cámara de Jaime</h1>
<p id="estado">Esperando video de la tablet…</p>
<img id="camara" alt="Video en vivo de la tablet">
</main><script>
const imagen=document.getElementById('camara');
const estado=document.getElementById('estado');
async function actualizar(){
  try{
    const respuesta=await fetch('/frame.jpg?t='+Date.now(),{cache:'no-store'});
    if(!respuesta.ok)throw Error('Sin imagen reciente');
    const blob=await respuesta.blob();
    const nueva=URL.createObjectURL(blob);
    const anterior=imagen.dataset.url;
    imagen.src=nueva;
    imagen.dataset.url=nueva;
    if(anterior)URL.revokeObjectURL(anterior);
    estado.textContent='Video en vivo';
  }catch(e){estado.textContent='Esperando video de la tablet…';}
  setTimeout(actualizar,200);
}
actualizar();
</script></body></html>""",
        content_type="text/html",
        headers={"Cache-Control": "no-store", "X-Content-Type-Options": "nosniff"},
    )


async def imagen_actual(request):
    if ultimo_jpeg is None or time.monotonic() - instante_jpeg > 3:
        return web.Response(status=503, text="Sin video reciente")
    return web.Response(
        body=ultimo_jpeg,
        content_type="image/jpeg",
        headers={"Cache-Control": "no-store", "X-Content-Type-Options": "nosniff"},
    )


async def offer(request):
    parametros = await request.json()
    oferta = RTCSessionDescription(sdp=parametros["sdp"], type=parametros["type"])
    pc = RTCPeerConnection()
    pcs.add(pc)
    print("Nueva conexión WebRTC", flush=True)

    @pc.on("connectionstatechange")
    async def on_connectionstatechange():
        print("Estado WebRTC:", pc.connectionState, flush=True)
        if pc.connectionState in ("failed", "closed"):
            await pc.close()
            pcs.discard(pc)

    @pc.on("track")
    def on_track(track):
        print("Track recibido:", track.kind, flush=True)
        if track.kind == "video":
            asyncio.create_task(recibir_video(track))

    try:
        await pc.setRemoteDescription(oferta)
        respuesta = await pc.createAnswer()
        await pc.setLocalDescription(respuesta)
    except Exception:
        await pc.close()
        pcs.discard(pc)
        raise

    return web.json_response(
        {"sdp": pc.localDescription.sdp, "type": pc.localDescription.type},
        headers={"Access-Control-Allow-Origin": "*"},
    )


async def options(request):
    return web.Response(headers={
        "Access-Control-Allow-Origin": "*",
        "Access-Control-Allow-Headers": "Content-Type",
        "Access-Control-Allow-Methods": "POST, OPTIONS",
    })


async def cerrar_conexiones(app):
    await asyncio.gather(*(pc.close() for pc in pcs), return_exceptions=True)
    pcs.clear()


app = web.Application()
app.router.add_post("/offer", offer)
app.router.add_options("/offer", options)
app.router.add_get("/view", visor)
app.router.add_get("/frame.jpg", imagen_actual)
app.on_shutdown.append(cerrar_conexiones)


if __name__ == "__main__":
    print("Receptor WebRTC sin ventana iniciado en puerto 8080", flush=True)
    print("Visor LAN: http://IP_DEL_PC:8768/view (requiere redirección de Windows)", flush=True)
    web.run_app(app, host="0.0.0.0", port=8080)