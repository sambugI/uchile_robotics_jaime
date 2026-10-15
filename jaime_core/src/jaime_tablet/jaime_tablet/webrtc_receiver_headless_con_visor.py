"""Receptor WebRTC de Jaime con visor de cámara de solo lectura por LAN."""

import asyncio
import io
import time

from aiohttp import web
from aiortc import RTCPeerConnection, RTCSessionDescription


pcs = set()
ultimo_jpeg = None
instante_jpeg = 0.0
intervalo_jpeg = 0.1  # Hasta diez imágenes por segundo para el visor LAN.


def comprimir_frame(frame):
    """La conversión JPEG se realiza fuera del hilo de asyncio."""
    salida = io.BytesIO()
    frame.to_image().save(salida, format="JPEG", quality=95, optimize=False)
    return salida.getvalue()


async def actualizar_visor(frame):
    """Prepara un cuadro sin frenar la recepción del video WebRTC."""
    global ultimo_jpeg, instante_jpeg
    try:
        nuevo_jpeg = await asyncio.to_thread(comprimir_frame, frame)
        ultimo_jpeg = nuevo_jpeg
        instante_jpeg = time.monotonic()
    except Exception as error:
        print("No se pudo preparar la imagen para el visor:", error, flush=True)


async def recibir_video(track):
    frames_totales = 0
    frames_intervalo = 0
    inicio_total = time.monotonic()
    inicio_intervalo = inicio_total
    tarea_codificacion = None
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
            if (ahora - instante_jpeg >= intervalo_jpeg and
                    (tarea_codificacion is None or tarea_codificacion.done())):
                tarea_codificacion = asyncio.create_task(actualizar_visor(frame))
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
    finally:
        if tarea_codificacion is not None and not tarea_codificacion.done():
            tarea_codificacion.cancel()


async def visor(request):
    return web.Response(
        text="""<!doctype html>
<html lang="es">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Jaime · Visor de cámara</title>
  <style>
    :root { color-scheme: dark; --bg:#07111b; --surface:#101d2b; --line:#26394b;
      --text:#f1f7fc; --muted:#9dafbf; --blue:#63ccf5; --green:#65e5ac; }
    * { box-sizing:border-box; }
    html,body { margin:0; min-height:100%; background:var(--bg); color:var(--text);
      font-family:Inter,system-ui,-apple-system,"Segoe UI",sans-serif; }
    body { background:radial-gradient(circle at 50% -15%,#17334a 0%,var(--bg) 52%); }
    .shell { width:min(1120px,100%); margin:auto; padding:28px 28px 34px; }
    header { display:flex; justify-content:space-between; align-items:center; gap:20px;
      margin-bottom:24px; }
    .brand { display:flex; align-items:center; gap:15px; }
    .mark { width:44px; height:44px; display:grid; place-items:center; border-radius:14px;
      color:var(--blue); background:#14283a; border:1px solid #30506a; font-size:23px; }
    .brand strong { display:block; font-size:19px; letter-spacing:.16em; }
    .brand small { display:block; color:var(--muted); font-size:12px; margin-top:2px; }
    .badge { display:flex; align-items:center; gap:9px; padding:10px 14px; border-radius:99px;
      border:1px solid var(--line); background:#122231; color:var(--muted); font-size:13px;
      font-weight:650; white-space:nowrap; }
    .dot { width:8px; height:8px; border-radius:50%; background:#e9b96b; box-shadow:0 0 12px #e9b96b88; }
    .online .dot { background:var(--green); box-shadow:0 0 12px #65e5acaa; }
    h1 { margin:0 0 5px; font-size:clamp(25px,3vw,34px); letter-spacing:-.035em; }
    .subtitle { margin:0 0 20px; color:var(--muted); font-size:14px; }
    .stage { position:relative; display:flex; align-items:center; justify-content:center;
      min-height:min(66vh,600px); padding:52px 24px; overflow:hidden; border-radius:20px;
      background:#03070c; border:1px solid #294154;
      box-shadow:0 24px 70px #0006, inset 0 0 0 1px #ffffff08; }
    .stage:fullscreen { border:0; border-radius:0; padding:44px; }
    .stage:fullscreen img { max-height:calc(100vh - 88px); }
    .stage img { display:block; width:auto; height:auto; max-width:100%;
      max-height:calc(66vh - 42px); object-fit:contain; opacity:0; }
    .stage.online img { opacity:1; }
    .stage-label { position:absolute; top:19px; left:20px; z-index:2; padding:7px 10px;
      border:1px solid #ffffff24; border-radius:7px; background:#07111bcc;
      color:#d6e9f4; font-size:11px; font-weight:750; letter-spacing:.12em; }
    .placeholder { position:absolute; display:grid; justify-items:center; gap:12px;
      padding:25px; text-align:center; color:var(--muted); }
    .placeholder svg { color:var(--blue); opacity:.8; }
    .placeholder strong { color:var(--text); font-size:17px; }
    .stage.online .placeholder { display:none; }
    .footer { display:flex; align-items:center; justify-content:space-between; flex-wrap:wrap;
      gap:16px; margin-top:16px; padding:16px 19px; border:1px solid var(--line);
      border-radius:14px; background:#101f2d; }
    .metrics { display:flex; align-items:center; flex-wrap:wrap; gap:10px 22px; }
    .metric { display:grid; gap:3px; }
    .metric span { color:var(--muted); font-size:11px; text-transform:uppercase;
      letter-spacing:.1em; }
    .metric strong { font-size:14px; font-weight:650; font-variant-numeric:tabular-nums; }
    button { border:1px solid #36566e; border-radius:10px; background:#1b3449;
      color:var(--text); padding:11px 15px; font:650 13px inherit; cursor:pointer; }
    button:hover { background:#254762; }
    .note { margin:15px 2px 0; color:#8296a8; font-size:12px; line-height:1.5; }
    @media(max-width:600px) { .shell { padding:17px 14px 24px; } header { margin-bottom:25px; }
      .badge { font-size:12px; padding:9px 11px; } .stage { min-height:58vh; padding:44px 12px; }
      .stage img { max-height:calc(58vh - 30px); } .footer { align-items:stretch; }
      button { width:100%; } }
  </style>
</head>
<body>
  <main class="shell">
    <header>
      <div class="brand"><div class="mark" aria-hidden="true">◉</div>
        <div><strong>JAIME</strong><small>Monitor de cámara</small></div></div>
      <div class="badge" id="indicador"><span class="dot"></span><span id="estado">Esperando señal</span></div>
    </header>
    <h1>Vista en tiempo real</h1>
    <p class="subtitle">Video recibido desde la tablet</p>
    <section class="stage" id="visor" aria-label="Video de la tablet">
      <div class="stage-label">CAM 01 · TABLET</div>
      <img id="camara" alt="Video en vivo de la tablet">
      <div class="placeholder" id="espera">
        <svg width="48" height="48" viewBox="0 0 48 48" fill="none" aria-hidden="true">
          <rect x="5" y="12" width="30" height="24" rx="5" stroke="currentColor" stroke-width="2"/>
          <path d="m35 20 8-5v18l-8-5" stroke="currentColor" stroke-width="2" stroke-linejoin="round"/>
          <circle cx="20" cy="24" r="5" stroke="currentColor" stroke-width="2"/>
        </svg>
        <strong>Esperando video de la tablet</strong>
        <span>Inicia la cámara en Jaime para verla aquí.</span>
      </div>
    </section>
    <div class="footer">
      <div class="metrics">
        <div class="metric"><span>Resolución recibida</span><strong id="resolucion">—</strong></div>
        <div class="metric"><span>Edad del cuadro en receptor</span><strong id="edad">—</strong></div>
        <div class="metric"><span>Última imagen</span><strong id="hora">—</strong></div>
      </div>
      <button type="button" id="pantallaCompleta">Pantalla completa</button>
    </div>
    <p class="note">La edad del cuadro mide el tramo entre el receptor y este visor.</p>
  </main>
  <script>
    const imagen=document.getElementById('camara');
    const visor=document.getElementById('visor');
    const indicador=document.getElementById('indicador');
    const estado=document.getElementById('estado');
    const edad=document.getElementById('edad');
    const resolucion=document.getElementById('resolucion');
    const hora=document.getElementById('hora');
    const boton=document.getElementById('pantallaCompleta');
    boton.addEventListener('click',async()=>{
      try { if(document.fullscreenElement) await document.exitFullscreen();
        else await visor.requestFullscreen(); } catch(error) { console.warn(error); }
    });
    document.addEventListener('fullscreenchange',()=>{
      boton.textContent=document.fullscreenElement?'Salir de pantalla completa':'Pantalla completa';
    });
    async function actualizar(){
      let nuevaUrl=null;
      try {
        const respuesta=await fetch('/frame.jpg?t='+Date.now(),{cache:'no-store'});
        if(!respuesta.ok) throw new Error('Sin imagen reciente');
        const blob=await respuesta.blob();
        nuevaUrl=URL.createObjectURL(blob);
        const siguiente=new Image();
        siguiente.src=nuevaUrl;
        await siguiente.decode();
        const anterior=imagen.dataset.url;
        imagen.src=nuevaUrl;
        imagen.dataset.url=nuevaUrl;
        nuevaUrl=null;
        if(anterior) URL.revokeObjectURL(anterior);
        visor.classList.add('online');
        indicador.classList.add('online');
        estado.textContent='Video en vivo';
        resolucion.textContent=siguiente.naturalWidth+' × '+siguiente.naturalHeight;
        const ms=respuesta.headers.get('X-Frame-Age-Ms');
        edad.textContent=ms ? ms+' ms' : '—';
        hora.textContent=new Date().toLocaleTimeString('es-CL');
      } catch(error) {
        if(nuevaUrl) URL.revokeObjectURL(nuevaUrl);
        visor.classList.remove('online');
        indicador.classList.remove('online');
        estado.textContent='Esperando señal';
        edad.textContent='—';
      }
      setTimeout(actualizar,100);
    }
    actualizar();
  </script>
</body>
</html>""",
        content_type="text/html",
        headers={"Cache-Control": "no-store", "X-Content-Type-Options": "nosniff"},
    )


async def imagen_actual(request):
    if ultimo_jpeg is None or time.monotonic() - instante_jpeg > 3:
        return web.Response(status=503, text="Sin video reciente")
    return web.Response(
        body=ultimo_jpeg,
        content_type="image/jpeg",
        headers={
            "Cache-Control": "no-store",
            "X-Content-Type-Options": "nosniff",
            "X-Frame-Age-Ms": str(round((time.monotonic() - instante_jpeg) * 1000)),
        },
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
    print("Visor local: http://127.0.0.1:8080/view", flush=True)
    web.run_app(app, host="0.0.0.0", port=8080)
