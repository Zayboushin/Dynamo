#include <Arduino.h>
#include "motores/motores.h"
#include "pistaA.h"
// primer pista

// variables del reto
const byte MAX_TURNS = 10;
char posiciones_avance[MAX_TURNS];
// variables para reto
//  l = “left”;
//  r = “right”;
//  u = “up”;
//  d = “down”;
// test

// variables de control (falta cambiar)
int P = 0;
int I = 0;
int D = 0;
int vel = 250;

// logica
bool giro_pendiente = false;

byte lateralidad = 0;
// izquierda = 1
// derecha = 2

byte cercania_pared = 5; // valor que define que tan cerca estara de la pared una vez se defina la lateralidad. revisar que valor es mejor

byte choque_inminente = 15; // distancia en donde se detecta que hay una pared

void setup()
{
}

void loop()
{
}