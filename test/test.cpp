#include <Arduino.h>
#include <Adafruit_MPU6050.h>
#include <Wire.h>
#include "motores.h"

Adafruit_MPU6050 mpu;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  for (uint8_t dir = 1; dir < 127; dir++)
  {
    Wire.beginTransmission(dir);
    if (dir == 0x69)
    {
      avanzar(100, 100);
    }
    if (Wire.endTransmission() == 0)
    {
      Serial.print("Dispositivo en 0x");
      Serial.println(dir, HEX);
    }
  }
  Serial.println("Escaneo terminado");
}

void loop() {}
