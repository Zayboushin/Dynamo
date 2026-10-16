// author:leonardo Rodríguez

#include <Arduino.h>
#include "motores.h"
#include "sensores.h"
#include "control.h"
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

// variables nativas de sensores
float distancia_ultrasonico_izq = 0;
float distancia_ultrasonico_der = 0;

// logica
static bool giro_pendiente = false;

byte lateralidad = 0;
// izquierda = 1
// derecha = 2

static byte cercania_pared = 5; // valor que define que tan cerca estara de la pared una vez se defina la lateralidad. revisar que valor es mejor

static byte choque_inminente = 15; // distancia en donde se detecta que hay una pared

// funciones
static bool pared(ultrasonico &u);
static bool revision_giro(int lateralidad);

// Funcion principal
void pistaA()
{
    while (true)
    {
        // define la lateridad
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

        giro_pendiente = revision_giro(lateralidad);
        if (!giro_pendiente)
        {
            distancia_ultrasonico_izq = ultrasonico_izq.distancia_ultrasonico();
            distancia_ultrasonico_der = ultrasonico_der.distancia_ultrasonico();

            float correcion_izq = 0;
            float correcion_der = 0;

            avanzar_control(correcion_izq, correcion_der, distancia_ultrasonico_izq, distancia_ultrasonico_der);
            // regresa los valores de corrección para determinar el PWM final de los motores

            avanzar(correcion_izq, correcion_der);
            // revisar signos
        }
        else
        {
            giro(lateralidad);
            logica_90grados(giro_pendiente);
        }
    }
}

// funcion que determina si hay una pared cerca
static bool pared(ultrasonico &u)
{
    // De entrada, se recibe uno de los 3 ultrasónicos (enfrente, izquierda, derecha)

    float distancia = u.distancia_ultrasonico();

    if (distancia < choque_inminente)
    {
        return true; // devuelve verdadero si hay pared
    }

    else
    {
        return false; // devuelve falso si no hay pared
    }
}

static bool revision_giro(int lateralidad)
{
    // agregar condiciones que consideren los lados del sensor necesarios
    bool izq = false;
    bool der = false;
    bool frente = false;
    switch (lateralidad)
    {
    case 1:

        if (!pared(ultrasonico_izq))
        {
            return true;
        }
        break;

    case 2:
        if (!pared(ultrasonico_der))
        {
            return true;
        }
        break;
    }

    if (pared(ultrasonico_frente))
    {
        return true;
    }

    return false;
}

static void correcion_drift()
{
    // revisar que el drift no sea mayor a N centimetros.
}