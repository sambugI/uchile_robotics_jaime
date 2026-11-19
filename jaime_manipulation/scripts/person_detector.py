import cv2
import os
import sys

# ============================================================
# Configuración de rutas
# ============================================================

# Directorio donde se encuentra este script
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

# Directorio principal del paquete jaime_manipulation
PACKAGE_DIR = os.path.dirname(SCRIPT_DIR)

# Directorio de modelos
MODELS_DIR = os.path.join(PACKAGE_DIR, "models")

# Agregar models al path de Python
sys.path.insert(0, MODELS_DIR)

# Importar detector
from mp_persondet import MPPersonDet


# ============================================================
# Inicialización del detector
# ============================================================

MODEL_PATH = os.path.join(
    MODELS_DIR,
    "person_detection_mediapipe_2023mar.onnx"
)

if not os.path.isfile(MODEL_PATH):
    raise FileNotFoundError(
        f"No se encontró el modelo: {MODEL_PATH}"
    )

person_detector = MPPersonDet(
    modelPath=MODEL_PATH,
    scoreThreshold=0.5,
    nmsThreshold=0.3,
    topK=5
)


# ============================================================
# Cargar imagen
# ============================================================

IMAGE_PATH = os.path.join(SCRIPT_DIR, "test.jpg")

image = cv2.imread(IMAGE_PATH)

if image is None:
    raise FileNotFoundError(
        f"No se pudo cargar la imagen: {IMAGE_PATH}"
    )


# ============================================================
# Detección de personas
# ============================================================

persons = person_detector.infer(image)

print(f"Personas detectadas: {len(persons)}")


# ============================================================
# Dibujar detecciones
# ============================================================

for person in persons:

    bbox = person[0]

    x1, y1 = bbox[0]
    x2, y2 = bbox[1]

    cv2.rectangle(
        image,
        (int(x1), int(y1)),
        (int(x2), int(y2)),
        (0, 255, 0),
        2
    )


# ============================================================
# Visualización
# ============================================================

cv2.imshow("MP-PersonDet - Person Detection", image)

cv2.waitKey(0)
cv2.destroyAllWindows()