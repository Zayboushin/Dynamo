#include <Arduino.h>
#include "motores.h"
#include "sensores.h"
#include "control.h"
#include "pistaA.h"

void setup()
{

  Serial.begin(115200);
  iniciar_motores();
  iniciar_sensores();
  iniciar_IMU();
  calibrar_IMU();
}

void loop()
{
  avanzar(200,200);   // put your main code here, to run repeatedly:
}


/*

#include <Arduino.h>
#include <Wire.h>

void setup()
{
    Serial.begin(115200);
    Wire.begin();
    for (uint8_t dir = 1; dir < 127; dir++)
    {
        Wire.beginTransmission(dir);
        if (Wire.endTransmission() == 0)
        {
            Serial.print("Dispositivo en 0x");
            Serial.println(dir, HEX);
        }
    }
    Serial.println("Escaneo terminado");
}

void loop() {}

*/