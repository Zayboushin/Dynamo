#include <Arduino.h>
#include "sensores.h"

class ultrasonico
{
private:
    uint8_t trig;
    uint8_t echo;

public:
    ultrasonico();
    {
        trig = 0;
        echo = 0;
    }
    void setPins(uint8_t newTrig, uint8_t newEcho)
    {
        trig = newTrig;
        echo = newEcho;

        pinMode(trig, OUTPUT);
        pinMode(echo, INPUT);
        digitalWrite(trig, LOW);
    }
    float distancia_ultrasonico(ultrasonico);
    {
        long t = 0;

        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig, LOW);

        t = pulseIn(echo, HIGH);
        return (t / 58.2) f; // distancia en cm
    }
};

ultrasonico ultrasonico_izq;

ultrasonico ultrasonico_der;

ultrasonico ultrasonico_frente;

void setup()
{
    ultrasonico_izq.setPins(2, 3);    // Pines del ultrasonico izquierdo
    ultrasonico_der.setPins(4, 5);    // Pines del ultrasonico derecho
    ultrasonico_frente.setPins(6, 7); // Pines del ultrasonico frente
}