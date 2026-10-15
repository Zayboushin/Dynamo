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

  if (true)
  {
    pistaA();
  }
}

void loop()
{
   // put your main code here, to run repeatedly:
}
