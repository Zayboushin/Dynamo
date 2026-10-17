// author:leonardo Rodríguez
#include <Arduino.h>
#include "sensores.h"

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

    // Configuración de pines para los sensores infrarrojos (falta configurarlos)
    infrarrojo_izq.setPins(8); // Pines del sensor infrarrojo izquierdo
    infrarrojo_der.setPins(9); // Pines del sensor infrarrojo derecho
    infrarrojo_izq.begin();
    infrarrojo_der.begin();

    /*
    // Configuración de pines para el sensor RGB (falta configurarlos)
    sensor_rgb.setPins(45, 44, 46, 49, 48); // Pines del sensor RGB
    sensor_rgb.begin();
    pinMode(LIMIT_SWITCH, INPUT);
*/
}

// const uint8_t PIN_STBY = A2;
// const uint8_t LIMIT_SWITCH = 12;

// limit switch

// Karla :)
/*

//detectar tonalidad/color

if (rojo == 0 || verde == 0 || azul == 0) return "Desconocido";

    float r =  1000.0 / rojo;
    float g = 1000.0 / verde;
    float b = 1000.0 / azul;

    float mx = max(r, max(g, b));
    float mn = min(r, min(g, b));
    float diferencia = mx - mn;

  // Calcular el tono (0 a 360)
  float tono = 0;
  if (diferencia > 0) { //
    if (mx == r) {
        tono = 60 * ((g - b) / diferencia);
    }
    else if (mx == g) {
        tono = 60 * ((b - r) / diferencia + 2);
    }
    else {
        tono = 60 * ((r - g) / diferencia + 4);
    }
    if (tono < 0) {
        tono += 360;
    }
  }
//los numeros son suposiciones, necesito calibrar sensor de color y ajustarlos
  if (tono >= 10 && tono < 35) {
        return "NARANJA";
    }
    else if (tono >= 35 && tono < 80) {
        return "AMARILLO";
    }
    else if (tono >= 170 && tono < 260) {
        return "AZUL";
    }
    else if (tono >= 280 && tono < 345) {
        return "ROSA";
    }
    else {
    return "Desconocido";
    }


*/