#include <Arduino.h>
#include "motores/motores.h"
#include "sensores/sensores.h"

void setup()
{
  Serial.begin(9600);
  iniciar_motores();
  iniciar_sensores();
}

void loop()
{
  // put your main code here, to run repeatedly:
}
