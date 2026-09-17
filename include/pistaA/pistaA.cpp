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

// variables nativas de sensores
float distancia_ultrasonico_izq = 0;
float distancia_ultrasonico_der = 0;

// logica
bool giro_pendiente = false;

byte lateralidad = 0;
// izquierda = 1
// derecha = 2

byte cercania_pared = 5; // valor que define que tan cerca estara de la pared una vez se defina la lateralidad. revisar que valor es mejor

byte choque_inminente = 15; // distancia en donde se detecta que hay una pared

// funciones
bool pared(ultrasonico ultrasonico_entrada);
int calibracion(float distancia_ultrasonico_izq, float distancia_ultrasonico_der);
void correcion_drift();

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

    if (!giro_pendiente)
    {
        distancia_ultrasonico_izq = ultrasonico_izq.distancia_ultrasonico();
        distancia_ultrasonico_der = ultrasonico_der.distancia_ultrasonico();

        int corrección = calibracion(distancia_ultrasonico_izq, distancia_ultrasonico_der);
        // regresa los valores de corrección para determinar el PWM final de los motores

        avanzar(vel - corrección, vel + corrección);
        // revisar signos

        correcion_drift();
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

int calibracion(float distancia_ultrasonico_izq, float distancia_ultrasonico_der)
{
    int corrección = 0;
    float error = 0;

    if (lateralidad == 0)
    {
        error = distancia_ultrasonico_izq - distancia_ultrasonico_der;
    }
    else
    {
        switch (lateralidad)
        {

        case 1:
            error = distancia_ultrasonico_izq - cercania_pared;
            break;
        case 2:
            error = cercania_pared - distancia_ultrasonico_der;
            break;
        }
    }

    // P
    corrección = error * P;

    // I

    // D

    return corrección;
}

void correcion_drift()
{
    // revisar que el drift no sea mayor a N centimetros.
}