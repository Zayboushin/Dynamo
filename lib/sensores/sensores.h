// author:leonardo Rodríguez
#include <Arduino.h>
#ifndef SENSORES_H
#define SENSORES_H

String colores[] = {"azul",
                    "amarillo",
                    "naranja",
                    "rosa",
                    "rojo",
                    "verde",
                    "blanco",
                    "negro"};


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
extern ultrasonico ultrasonico_izq;
extern ultrasonico ultrasonico_der;
extern ultrasonico ultrasonico_frente;

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

    bool linea_blanca()
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

extern infrarrojo infrarrojo_izq;
extern infrarrojo infrarrojo_der;

class RGB
{
private:
    int s0;
    int s1;
    int s2;
    int s3;
    int out;

    int r;
    int v;
    int c;

public:
    RGB()
    {
        s0 = 0;
        s1 = 0;
        s2 = 0;
        s3 = 0;
        out = 0;
    }

    void setPins(int newS0, int newS1, int newS2, int newS3, int newOut)
    {
        s0 = newS0;
        s1 = newS1;
        s2 = newS2;
        s3 = newS3;
        out = newOut;
    }
    void begin()
    {
        pinMode(s0, OUTPUT);
        pinMode(s1, OUTPUT);
        pinMode(s2, OUTPUT);
        pinMode(s3, OUTPUT);
        pinMode(out, INPUT);

        digitalWrite(s0, HIGH);
        digitalWrite(s1, LOW);
    }

    String leer_color()
    {
        // Leer el color del sensor RGB
        digitalWrite(s2, LOW);
        digitalWrite(s3, LOW);
        r = pulseIn(out, LOW);

        digitalWrite(s2, HIGH);
        digitalWrite(s3, HIGH);
        v = pulseIn(out, LOW);

        digitalWrite(s2, LOW);
        digitalWrite(s3, HIGH);
        c = pulseIn(out, LOW);

        // cadena de texto con los valores de los colores (falta agregar forma de detectar el color)
        if (true)
        {
            return colores[0];
        }
        else if (true)
        {
            return colores[1];
        }
        else if (true)
        {
            return colores[2];
        }
        else
        {
            return colores[3];
        }

        return "R: " + String(r) + " V: " + String(v) + " C: " + String(c);
    }
};

extern RGB sensor_rgb;

void iniciar_sensores();

#endif