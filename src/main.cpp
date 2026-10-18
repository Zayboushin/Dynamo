#include <Arduino.h>
#include "motores.h"
#include "sensores.h"
#include "control.h"
#include "pistaA.h"

void setup()
{

  Serial.begin(115200);
  // RobotInstance.begin(); <-- Crear una lib que inicie todos lo sensores
  iniciar_motores();
}

void loop()
{
  desp_izq(100);
}