"""Panel local de telemetría de Jaime: http://127.0.0.1:8767."""

import asyncio
import json
import subprocess
import time

from aiohttp import web


lecturas = {}
baterias_robot = {}
tablet_conectada = False
estado_cache = None
ultima_consulta = 0.0

CAMPOS = {
    "battery": ("level", "charging", "power_source"),
    "accelerometer": ("x", "y", "z"),
    "gyroscope": ("x", "y", "z"),
    "orientation": ("azimuth", "pitch", "roll"),
    "sensor_status": ("accelerometer", "gyroscope", "orientation"),
}


def conectada(valor):
    global tablet_conectada, estado_cache, ultima_consulta
    tablet_conectada = valor
    lecturas.clear()
    estado_cache = None
    ultima_consulta = 0.0


def registrar(sensor, valores):
    if sensor not in CAMPOS or not isinstance(valores, dict):
        return
    lecturas[sensor] = {
        "values": {clave: valores.get(clave) for clave in CAMPOS[sensor]},
        "updated_at_ms": int(time.time() * 1000),
    }


async def consultar_estado():
    global estado_cache, ultima_consulta
    if not tablet_conectada:
        return None
    if time.monotonic() - ultima_consulta < 5:
        return estado_cache
    ultima_consulta = time.monotonic()
    escritor = None
    try:
        lector, escritor = await asyncio.open_connection("127.0.0.1", 8766)
        escritor.write(b'{"action":"status"}\n')
        await escritor.drain()
        linea = await asyncio.wait_for(lector.readline(), timeout=4)
        respuesta = json.loads(linea)
        estado_cache = respuesta.get("status") if respuesta.get("ok") else None
        return estado_cache
    except (OSError, ValueError, asyncio.TimeoutError):
        return None
    finally:
        if escritor is not None:
            escritor.close()
            try:
                await escritor.wait_closed()
            except OSError:
                pass


async def recibir_baterias_robot(request):
    try:
        payload = await request.json()
    except (ValueError, UnicodeDecodeError):
        return web.json_response({"ok": False, "error": "JSON inválido"}, status=400)

    if not isinstance(payload, dict):
        return web.json_response({"ok": False, "error": "Formato inválido"}, status=400)

    ahora_ms = int(time.time() * 1000)
    for clave in ("kobuki", "bms"):
        if clave in payload and isinstance(payload[clave], dict):
            baterias_robot[clave] = {
                **payload[clave],
                "updated_at_ms": ahora_ms,
            }
    return web.json_response({"ok": True})



async def datos(request):
    return web.json_response({
        "connected": tablet_conectada,
        "status": await consultar_estado(),
        "telemetry": lecturas,
        "robot_battery": baterias_robot,
        "time_ms": int(time.time() * 1000),
    }, headers={
        "Cache-Control": "no-store",
        "Access-Control-Allow-Origin": "*",
    })


HTML = r'''<!doctype html>
<html lang="es"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>Jaime · Telemetría</title>
<style>
:root{font-family:system-ui,Segoe UI,sans-serif;color-scheme:dark}
*{box-sizing:border-box}body{margin:0;color:#eaf3ff;background:radial-gradient(circle at top right,#183b62,#071525 55%);min-height:100vh}
main{max-width:1050px;margin:auto;padding:clamp(22px,4vw,55px)}header{display:flex;justify-content:space-between;align-items:center;gap:18px;flex-wrap:wrap;margin-bottom:28px}
.kicker{font-size:.8rem;color:#80b9ff;letter-spacing:.17em;font-weight:800}h1{font-size:clamp(2.5rem,6vw,4rem);letter-spacing:-.055em;margin:8px 0}p{color:#a7bed5;margin:0}
.badge,.card{background:#11243a;border:1px solid #2a496b}.badge{padding:11px 17px;border-radius:50px}.badge.on{color:#65e4bd;border-color:#42a989}
.grid{display:grid;grid-template-columns:repeat(2,minmax(0,1fr));gap:16px}.card{border-radius:19px;padding:24px;min-width:0}.wide{grid-column:span 2}
h2{font-size:.84rem;letter-spacing:.13em;text-transform:uppercase;color:#92badf;margin:0 0 18px}.big{font-size:clamp(2rem,4vw,3rem);font-weight:750}
.muted{color:#a7bed5;margin-top:8px}.axes{display:grid;grid-template-columns:repeat(3,minmax(0,1fr));gap:10px}.axis{background:#19324f;border-radius:12px;padding:12px}
.axis small{display:block;color:#9bb6d0;margin-bottom:8px}.axis strong{font-size:clamp(1.15rem,2.5vw,1.8rem);font-variant-numeric:tabular-nums;overflow-wrap:anywhere}
.btn{border:1px solid #4689c6;background:#1d4c77;color:#fff;border-radius:9px;padding:10px 14px;margin:12px 7px 0 0;cursor:pointer}
.btn:disabled{opacity:.5;cursor:not-allowed}
footer{margin-top:26px;color:#91aac5;font-size:.85rem}@media(max-width:650px){.grid{grid-template-columns:1fr}.wide{grid-column:auto}.card{padding:18px}}
</style></head><body><main><header><div><div class="kicker">PROYECTO JAIME · ROBOT ↔ TABLET</div><h1>Telemetría</h1><p>Estado de baterías y sensores del sistema</p></div><div class="badge" id="conexion">Conectando…</div></header>
<section class="grid">
<article class="card"><h2>Batería Base Kobuki</h2><div class="big" id="bat-kobuki">—</div><div class="muted" id="bat-kobuki-det">Sin datos de ROS</div></article>
<article class="card"><h2>Pack Externo BMS</h2><div class="big" id="bat-bms">—</div><div class="muted" id="bat-bms-det">Desconectado o sin datos</div></article>
<article class="card"><h2>Batería Tablet</h2><div class="big" id="battery">—</div><div class="muted" id="charge">Esperando datos</div></article>
<article class="card"><h2>Cámara</h2><div class="big" id="camera">—</div><div class="muted" id="webrtc">WebRTC: —</div><button class="btn" data-action="camera_start">Iniciar cámara</button><button class="btn" data-action="camera_stop">Detener cámara</button><div class="muted" id="command-result" aria-live="polite"></div></article>
<article class="card wide"><h2>Acelerómetro · m/s²</h2><div class="axes"><div class="axis"><small>X</small><strong id="acc-x">—</strong></div><div class="axis"><small>Y</small><strong id="acc-y">—</strong></div><div class="axis"><small>Z</small><strong id="acc-z">—</strong></div></div><div class="muted" id="magnitude">Magnitud: —</div></article>
<article class="card"><h2>Giroscopio · rad/s</h2><div class="axes"><div class="axis"><small>X</small><strong id="gyro-x">—</strong></div><div class="axis"><small>Y</small><strong id="gyro-y">—</strong></div><div class="axis"><small>Z</small><strong id="gyro-z">—</strong></div></div><div class="muted" id="gyro-age">—</div></article>
<article class="card"><h2>Orientación · grados</h2><div class="axes"><div class="axis"><small>Azimut</small><strong id="ori-azimuth">—</strong></div><div class="axis"><small>Inclinación</small><strong id="ori-pitch">—</strong></div><div class="axis"><small>Giro lateral</small><strong id="ori-roll">—</strong></div></div><div class="muted" id="ori-age">—</div></article>
</section>
<footer id="foot">Actualizando cada 2 segundos · Panel local en este PC</footer></main>
<script>
const el=id=>document.getElementById(id),fmt=(v,d=2)=>v!=null&&Number.isFinite(Number(v))?Number(v).toFixed(d):'—';
function axes(prefix,item,keys,now){const ok=item&&now-item.updated_at_ms<8000;for(const key of keys)el(prefix+'-'+key).textContent=ok?fmt(item.values[key]):'—';return !!ok}
function age(item,now){return item?`Última lectura hace ${Math.max(0,Math.round((now-item.updated_at_ms)/1000))} s`:'Sin datos'}
function renderRobotBat(idMain,idDet,item,now,withCurrent){
  const ok=item&&item.present&&(now-item.updated_at_ms<10000);
  if(!ok){el(idMain).textContent='—';el(idDet).textContent='Sin lectura activa';return}
  const pct=item.percentage!=null?fmt(item.percentage,0)+'%':'—';
  const volt=item.voltage!=null?fmt(item.voltage,2)+' V':'—';
  el(idMain).textContent=`${pct} · ${volt}`;
  const est=item.charging?'Cargando':'En descarga';
  const corr=(withCurrent&&item.current!=null)?` · ${fmt(item.current,2)} A`:'';
  el(idDet).textContent=est+corr;
}
let busy=false;
async function update(){if(busy)return;busy=true;try{const response=await fetch('/api/telemetry',{cache:'no-store'});if(!response.ok)throw Error('sin respuesta');const d=await response.json(),t=d.telemetry||{},rb=d.robot_battery||{},now=d.time_ms;
el('conexion').textContent=d.connected?'● Tablet conectada':'○ Tablet desconectada';el('conexion').classList.toggle('on',d.connected);
renderRobotBat('bat-kobuki','bat-kobuki-det',rb.kobuki,now,false);
renderRobotBat('bat-bms','bat-bms-det',rb.bms,now,true);
const b=t.battery,bok=b&&now-b.updated_at_ms<120000;el('battery').textContent=bok?fmt(b.values.level,0)+'%':'—';el('charge').textContent=bok?`${b.values.charging?'Cargando':'Sin cargar'} · ${b.values.power_source||'sin fuente'}`:'Esperando datos';
el('camera').textContent=d.status?(d.status.camera_active?'Activa':'Detenida'):'—';el('webrtc').textContent='WebRTC: '+(d.status?.webrtc||'—');
const a=t.accelerometer;if(axes('acc',a,['x','y','z'],now)){const v=a.values;el('magnitude').textContent='Magnitud: '+(Number.isFinite(Number(v.x))&&Number.isFinite(Number(v.y))&&Number.isFinite(Number(v.z))?fmt(Math.hypot(v.x,v.y,v.z),3):'—')+' m/s² · '+age(a,now)}else el('magnitude').textContent='Magnitud: — · '+age(a,now);
el('gyro-age').textContent=age(t.gyroscope,now);axes('gyro',t.gyroscope,['x','y','z'],now);el('ori-age').textContent=age(t.orientation,now);axes('ori',t.orientation,['azimuth','pitch','roll'],now);
el('foot').textContent='Última consulta: '+new Date().toLocaleTimeString()+' · Panel local';
}catch(e){el('conexion').textContent='○ Servidor no disponible';el('conexion').classList.remove('on');el('foot').textContent='Sin conexión con el panel'}finally{busy=false}}
for(const button of document.querySelectorAll('button[data-action]')){
  button.addEventListener('click',async()=>{
    const buttons=document.querySelectorAll('button[data-action]');
    buttons.forEach(b=>b.disabled=true);
    el('command-result').textContent='Enviando orden…';
    try{
      const response=await fetch('/api/camera',{method:'POST',headers:{'Content-Type':'application/json'},body:JSON.stringify({action:button.dataset.action})});
      const result=await response.json();
      el('command-result').textContent=result.ok?'Orden confirmada por la tablet':(result.error||'Error');
      await update();
    }catch(error){el('command-result').textContent='Error de conexión'}
    finally{buttons.forEach(b=>b.disabled=false)}
  });
}
update();setInterval(update,2000);
</script></body></html>'''


async def pagina(request):
    return web.Response(text=HTML, content_type="text/html", charset="utf-8")


async def controlar_camara(request):
    global estado_cache, ultima_consulta
    if not tablet_conectada:
        return web.json_response({"ok": False, "error": "Tablet desconectada"}, status=503)
    try:
        solicitud = await request.json()
    except (ValueError, UnicodeDecodeError):
        return web.json_response({"ok": False, "error": "JSON inválido"}, status=400)
    accion = solicitud.get("action") if isinstance(solicitud, dict) else None
    if accion not in ("camera_start", "camera_stop"):
        return web.json_response({"ok": False, "error": "Acción inválida"}, status=400)
    escritor = None
    try:
        lector, escritor = await asyncio.open_connection("127.0.0.1", 8766)
        escritor.write((json.dumps({"action": accion}) + "\n").encode())
        await escritor.drain()
        linea = await asyncio.wait_for(lector.readline(), timeout=18)
        respuesta = json.loads(linea)
        if respuesta.get("ok"):
            estado_cache = respuesta.get("status")
            ultima_consulta = time.monotonic()
        return web.json_response(respuesta, status=200 if respuesta.get("ok") else 502)
    except (OSError, ValueError, asyncio.TimeoutError):
        return web.json_response({"ok": False, "error": "Sin respuesta del control"}, status=502)
    finally:
        if escritor is not None:
            escritor.close()
            try:
                await escritor.wait_closed()
            except OSError:
                pass


async def iniciar():
    try:
        subprocess.run(["adb", "-d", "reverse", "tcp:8767", "tcp:8767"], check=False)
    except FileNotFoundError:
        pass

    app = web.Application()
    app.router.add_get("/", pagina)
    app.router.add_get("/api/telemetry", datos)
    app.router.add_post("/api/camera", controlar_camara)
    app.router.add_post("/api/robot_battery", recibir_baterias_robot)
    runner = web.AppRunner(app)
    await runner.setup()
    try:
        await web.TCPSite(runner, "127.0.0.1", 8767).start()
    except Exception:
        await runner.cleanup()
        raise
    print("Panel local activo en: http://127.0.0.1:8767", flush=True)
    return runner


async def _ejecutar_standalone():
    runner = await iniciar()
    try:
        await asyncio.Event().wait()
    finally:
        await runner.cleanup()


def main():
    try:
        asyncio.run(_ejecutar_standalone())
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()