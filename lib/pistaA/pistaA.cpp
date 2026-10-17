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

static byte choque_lateral_inminente = 15; // distancia en donde se detecta que hay una pared
static byte choque_frontal_inminente = 10; // distancia en donde se detecta que hay una pared

// funciones
bool pared_lateral(ultrasonico &u);
bool pared_frontal(ultrasonico &u);
bool revision_giro(byte &lateralidad_temporal);

// Funcion principal
void pistaA()
{
    byte lateralidad_temporal = 0;
    while (true)
    {
        // define la lateridad
        if (lateralidad == 0)
        {
            if (!pared_lateral(ultrasonico_izq))
            {
                lateralidad = 1;
            }

            else if (!pared_lateral(ultrasonico_der))
            {
                lateralidad = 2;
            }
        }

        if (!giro_pendiente)
        {
            lateralidad_temporal = lateralidad;
            giro_pendiente = revision_giro(lateralidad_temporal);

            distancia_ultrasonico_izq = ultrasonico_izq.distancia_ultrasonico();
            distancia_ultrasonico_der = ultrasonico_der.distancia_ultrasonico();

            float correcion_izq = 0;
            float correcion_der = 0;

            avanzar_control(correcion_izq,
                            correcion_der,
                            cercania_pared,
                            (lateralidad == 1) ? distancia_ultrasonico_izq : distancia_ultrasonico_der,
                            lateralidad);
            // regresa los valores de corrección para determinar el PWM final de los motores

            avanzar(correcion_izq, correcion_der);
            // revisar signos
        }

        if (giro_pendiente)
        {
            if (lateralidad_temporal == 1)
            {
                izquierda(150);
            }
            else if (lateralidad_temporal == 2)
            {
                derecha(150);
            }
            logica_90grados(giro_pendiente);
        }
        lateralidad_temporal = 0;
    }
}

// funcion que determina si hay una pared cerca
bool pared_lateral(ultrasonico &u)
{
    // De entrada, se recibe uno de los 3 ultrasónicos (enfrente, izquierda, derecha)

    float distancia = u.distancia_ultrasonico();

    if (distancia < choque_lateral_inminente)
    {
        return true; // devuelve verdadero si hay pared
    }

    else
    {
        return false; // devuelve falso si no hay pared
    }
}

bool pared_frontal()
{
    // De entrada, se recibe uno de los 3 ultrasónicos (enfrente, izquierda, derecha)

    float distancia = ultrasonico_frente.distancia_ultrasonico();

    if (distancia < choque_frontal_inminente)
    {
        return true; // devuelve verdadero si hay pared
    }

    else
    {
        return false; // devuelve falso si no hay pared
    }
}

bool revision_giro(byte &lateralidad_temporal)
{
    // agregar condiciones que consideren los lados del sensor necesarios
    switch (lateralidad_temporal)
    {
    case 1:

        if (!pared_lateral(ultrasonico_izq))
        {
            lateralidad_temporal = 1;
            return true;
        }
        break;

    case 2:
        if (!pared_lateral(ultrasonico_der))
        {
            lateralidad_temporal = 2;
            return true;
        }
        break;
    }
    if (pared_frontal())
    {
        // cambio de valor de lateralidad para giro normal
        if (lateralidad_temporal == 1)
        {
            lateralidad_temporal = 2;
        }
        else if (lateralidad_temporal == 2)
        {
            lateralidad_temporal = 1;
        }

        return true;
    }

    return false;
}