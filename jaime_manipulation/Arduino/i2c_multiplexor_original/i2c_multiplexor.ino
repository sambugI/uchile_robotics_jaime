#include <Wire.h>
#include <PacketSerial.h>

#define AS5600_ADDR     0x36
#define TCA9548A_ADDR   0x70

PacketSerial myPacketSerial;

void tcaSelect(uint8_t bus) {
  if (bus > 7) return;
  Wire.beginTransmission(TCA9548A_ADDR);
  Wire.write(1 << bus);
  Wire.endTransmission();
  delayMicroseconds(300); // pequeño retardo tras cambiar de canal
}

uint16_t readAngle() {
  Wire.beginTransmission(AS5600_ADDR);
  Wire.write(0x0E); // Registro de ANGLE (MSB)
  if (Wire.endTransmission(false) != 0) return 0; // maneja NACK

  Wire.requestFrom(AS5600_ADDR, (uint8_t)2);
  if (Wire.available() < 2) return 0;

  uint16_t rawAngle = (Wire.read() << 8) | Wire.read();
  return rawAngle & 0x0FFF; // solo 12 bits válidos
}

void setup() {
  Serial.begin(9600);        // velocidad de puerto más alta
  Wire.begin();
  myPacketSerial.setStream(&Serial);
  Serial.println("Reading from multiple AS5600 sensors via TCA9548A...");
}

void loop() {
  myPacketSerial.update();
  float angles[4];

  for (int i = 0; i < 4; i++) {
    tcaSelect(i);
    uint16_t raw = readAngle();

    float ang = (raw * 360.0f) / 4096.0f;

    // Convertir de 0–360 a -180–180
    if (ang > 180.0f) {
      ang -= 360.0f;
    }
    
    angles[i] = ang * (3.14159265358979323846f / 180.0f);
  }


  // Empaqueta todos los datos en un solo paquete
  myPacketSerial.send(reinterpret_cast<uint8_t*>(angles), sizeof(angles));

  delay(5); // ~50 Hz de actualización
}
