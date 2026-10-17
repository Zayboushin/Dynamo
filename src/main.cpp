#include <Arduino.h>
#include "motores.h"
#include "sensores.h"
#include "control.h"
#include "pistaA.h"
#include "pistaB.h"

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
 pistaB();
}
