#include <Arduino.h>
#include "motores.h"
#include "sensores.h"
#include "control.h"
#include "pistaA.h"

void setup()
{
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin(115200);
  iniciar_motores();
  iniciar_sensores();

  iniciar_IMU();
  calibrar_IMU();

  if (true)
  {
    pistaA();
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
}
