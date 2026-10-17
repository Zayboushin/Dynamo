// author:leonardo Rodríguez
#include <Arduino.h>
#include "sensores.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_TCS34725.h>

String colores[] = {"azul",
                    "amarillo",
                    "naranja",
                    "rosa",
                    "rojo",
                    "verde",
                    "blanco",
                    "negro"};

// Clase para manejar los sensores ultrasónicos

ultrasonico ultrasonico_izq;
ultrasonico ultrasonico_der;
ultrasonico ultrasonico_frente;

// Función para iniciar los sensores ultrasónicos

infrarrojo infrarrojo_izq;
infrarrojo infrarrojo_der;

RGB sensor_rgb;

byte LIMIT_SWITCH = 12;

bool retroalimentacion_limit_switch()
{
    return digitalRead(LIMIT_SWITCH); // Devuelve true si el limit switch está activado (LOW)
}

// funcion final para iniciación de sensores
void iniciar_sensores()
{
    // trig, echo
    //  Configuración de pines para los sensores ultrasónicos (falta configurarlos)
    ultrasonico_izq.setPins(25, 24);    // Pines del ultrasonico izquierdo
    ultrasonico_der.setPins(26, 27);    // Pines del ultrasonico derecho
    ultrasonico_frente.setPins(28, 29); // Pines del ultrasonico frente
    ultrasonico_izq.begin();
    ultrasonico_der.begin();
    ultrasonico_frente.begin();

    if (!sensor_rgb.begin())
    {
        Serial.println(F("TCS34725 no encontrado (el carro sigue sin color)"));
    }

    // Configuración de pines para los sensores infrarrojos (falta configurarlos)
    infrarrojo_izq.setPins(8); // Pines del sensor infrarrojo izquierdo
    infrarrojo_der.setPins(9); // Pines del sensor infrarrojo derecho
    infrarrojo_izq.begin();
    infrarrojo_der.begin();
}
