// author:leonardo Rodríguez
#ifndef SENSORES_H
#define SENSORES_H

#include <Wire.h>
#include <Adafruit_TCS34725.h>
#include <Arduino.h>

extern String colores[8];

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

        t = pulseIn(echo, HIGH, 25000UL);
        if (t == 0)
            return 400.0f;
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
    Adafruit_TCS34725 tcs;
    bool listo;

    // Tu lógica de color, pero devolviendo los nombres de colores[]
    // (azul, amarillo, naranja, rosa, rojo, verde, blanco, negro)
    static String clasificar(uint16_t r, uint16_t g, uint16_t b, uint16_t c)
    {
        if (c < 100)
            return colores[7]; // negro

        float rn = (float)r / c, gn = (float)g / c, bn = (float)b / c;
        float mx = max(rn, max(gn, bn));
        float mn = min(rn, min(gn, bn));
        float delta = mx - mn;
        float sat = (mx > 0) ? delta / mx : 0;

        if (sat < 0.15)
        {
            if (c > 3000)
                return colores[6]; // blanco (CALIBRAR)
            return "desconocido";  // gris
        }

        float h;
        if (mx == rn)
            h = 60 * fmod(((gn - bn) / delta), 6);
        else if (mx == gn)
            h = 60 * (((bn - rn) / delta) + 2);
        else
            h = 60 * (((rn - gn) / delta) + 4);
        if (h < 0)
            h += 360;

        if (h < 15 || h >= 345)
            return colores[4]; // rojo
        if (h < 45)
            return colores[2]; // naranja
        if (h < 70)
            return colores[1]; // amarillo
        if (h < 165)
            return colores[5]; // verde
        if (h < 260 && h >= 200)
            return colores[0]; // azul
        if (h >= 290)
            return colores[3]; // rosa
        return "desconocido";  // cian / morado
    }

public:
    uint16_t r, g, b, c; // última lectura cruda, útil para calibrar

    RGB() : tcs(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X), listo(false)
    {
        r = g = b = c = 0;
    }

    bool begin()
    {
        listo = tcs.begin(); // dirección 0x29, usa Wire
        return listo;
    }

    bool disponible() { return listo; }

    // Bloquea ~51 ms. Devuelve un nombre de colores[] o "desconocido".
    String leer_color()
    {
        if (!listo)
            return "desconocido";
        tcs.getRawData(&r, &g, &b, &c);
        return clasificar(r, g, b, c);
    }
};

extern RGB sensor_rgb;

extern byte LIMIT_SWITCH;

bool retroalimentacion_limit_switch();

void iniciar_sensores();

#endif