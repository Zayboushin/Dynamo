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

infrarrojo infrarrojo_izq;
infrarrojo infrarrojo_der;

class RGB
{
private:
    uint8_t s0;
    uint8_t s1;
    uint8_t s2;
    uint8_t s3;
    uint8_t out;

    uint8_t r;
    uint8_t v;
    uint8_t c;

public:
    RGB()
    {
        s0 = 0;
        s1 = 0;
        s2 = 0;
        s3 = 0;
        out = 0;
    }

    void setPins(uint8_t newS0, uint8_t newS1, uint8_t newS2, uint8_t newS3, uint8_t newOut)
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

RGB sensor_rgb;

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

    // Configuración de pines para los sensores infrarrojos (falta configurarlos)
    infrarrojo_izq.setPins(8); // Pines del sensor infrarrojo izquierdo
    infrarrojo_der.setPins(9); // Pines del sensor infrarrojo derecho
    infrarrojo_izq.begin();
    infrarrojo_der.begin();

    // Configuración de pines para el sensor RGB (falta configurarlos)
    sensor_rgb.setPins(10, 11, 12, 13, 14); // Pines del sensor RGB
    sensor_rgb.begin();
}