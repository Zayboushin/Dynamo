#include <Arduino.h>
#include "motores.h"
#include "sensores.h"
#include "control.h"
#include "pistaA.h"

void setup()
{
  Serial.begin(9600);
  /*
    iniciar_motores();
    iniciar_sensores();
    iniciar_IMU();
    calibrar_IMU();
  */

  pinMode(A13, OUTPUT);
  pinMode(A11, OUTPUT);
  pinMode(4, OUTPUT);

  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(A8, OUTPUT);
  pinMode(A9, OUTPUT);
  pinMode(2, OUTPUT);

  pinMode(A10, OUTPUT);
  pinMode(A11, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{

  digitalWrite(A13, HIGH);
  digitalWrite(A11, LOW);
  analogWrite(4, 255);

  digitalWrite(46, LOW);
  digitalWrite(47, HIGH);
  analogWrite(5, 255);

  digitalWrite(A8, LOW);
  digitalWrite(A9, HIGH);
  analogWrite(2, 255);

  digitalWrite(A10, LOW);
  digitalWrite(A11, HIGH);
  analogWrite(3, 255);
}
