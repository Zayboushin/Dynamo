#include <Arduino.h>
#include "motores.h"
#include "sensores.h"
#include "control.h"
#include "pistaA.h"
#include "pistaB.h"

void setup()
{
  Serial.begin(9600);
  iniciar_motores();
  iniciar_sensores();
  iniciar_IMU();
}

void loop()
{
  avanzar(200,200);// put your main code here, to run repeatedly:
}
