#include <Arduino.h>
#include "sensores.h"

// Clase para manejar los sensores ultrasónicos
class ultrasonico
{
private:
    uint8_t trig;
    uint8_t echo;

public:
    ultrasonico()
    {
        trig = 0;
        echo = 0;
    }
    void setPins(uint8_t newTrig, uint8_t newEcho)
    {
        trig = newTrig;
        echo = newEcho;
    }

    void begin()
    {
        pinMode(trig, OUTPUT);
        pinMode(echo, INPUT);
        digitalWrite(trig, LOW);
    }

    float distancia_ultrasonico()
    {
        long t = 0;

        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig, LOW);

        t = pulseIn(echo, HIGH);
        return t / 58.2f; // distancia en cm
    }
};

ultrasonico ultrasonico_izq;
ultrasonico ultrasonico_der;
ultrasonico ultrasonico_frente;

// Función para iniciar los sensores ultrasónicos
class infrarrojo
{
private:
    uint8_t pin;

public:
    infrarrojo()
    {
        pin = 0;
    }
    void setPins(uint8_t newPin)
    {
        pin = newPin;
    }

    void begin()
    {
        pinMode(pin, INPUT);
    }

    // calibrar el sensor infrarrojo para detectar el color blanco y negro

    bool hay_blanco()
    {
        // calibrar el sensor infrarrojo para detectar el color blanco y negro
        bool lectura = digitalRead(pin);

        if (lectura)
        {
            return true; // Devuelve true si detecta blanco
        }
        else
        {
            return false;
        }
    }
};

infrarrojo infrarrojo_izq;
infrarrojo infrarrojo_der;

// funcion final para iniciación de sensores
void iniciar_sensores()
{
    // Configuración de pines para los sensores ultrasónicos (falta configurarlos)
    ultrasonico_izq.setPins(2, 3);    // Pines del ultrasonico izquierdo
    ultrasonico_der.setPins(4, 5);    // Pines del ultrasonico derecho
    ultrasonico_frente.setPins(6, 7); // Pines del ultrasonico frente

    ultrasonico_izq.begin();
    ultrasonico_der.begin();
    ultrasonico_frente.begin();

    infrarrojo_izq.setPins(8); // Pines del sensor infrarrojo izquierdo
    infrarrojo_der.setPins(9); // Pines del sensor infrarrojo derecho

    infrarrojo_izq.begin();
    infrarrojo_der.begin();
}