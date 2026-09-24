#include <Arduino.h>
#include "motores/motores.h"
#include "sensores/sensores.h"
#include "control/control.h"
#include "pistaA/pistaA.h"

void setup()
{

  Serial.begin(115200);
  iniciar_motores();
  iniciar_sensores();
  begin();
}

void loop()
{
  pistaA(); // put your main code here, to run repeatedly:
}
