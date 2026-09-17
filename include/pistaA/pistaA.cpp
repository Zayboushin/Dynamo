#include <Arduino.h>
#include "motores/motores.h"
#include "sensores/sensores.h"
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
    if (lateralidad == 0)
    {
        if (!pared(ultrasonico_izq))
        {
            lateralidad = 1;
        }

        if (!pared(ultrasonico_der))
        {
            lateralidad = 2;
        }
    }
}

bool pared(ultrasonico ultrasonico_entrada)
{
    // De entrada, se recibe uno de los 3 ultrasónicos (enfrente, izquierda, derecha)

    float distancia = ultrasonico_entrada.distancia_ultrasonico();

    if (distancia < choque_inminente)
    {
        return true; // devuelve verdadero si hay pared
    }

    else
    {
        return false; // devuelve falso si no hay pared
    }
}
