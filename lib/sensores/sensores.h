// author:leonardo Rodríguez
#include <Arduino.h>
#ifndef SENSORES_H
#define SENSORES_H

class ultrasonico
{
private:
    uint8_t trig;
    uint8_t echo;

public:
    ultrasonico();
    void setPins(uint8_t newTrig, uint8_t newEcho);
    void begin();
    float distancia_ultrasonico();
};
extern ultrasonico ultrasonico_izq;
extern ultrasonico ultrasonico_der;
extern ultrasonico ultrasonico_frente;

class infrarrojo
{
private:
    uint8_t pin;

public:
    infrarrojo();
    void setPins(uint8_t newPin);
    void begin();
    bool linea_blanca();
};

extern infrarrojo infrarrojo_izq;
extern infrarrojo infrarrojo_der;

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
    RGB();

    void setPins(uint8_t newS0, uint8_t newS1, uint8_t newS2, uint8_t newS3, uint8_t newOut);

    void begin();
    String leer_color();
};

extern RGB sensor_rgb;

void iniciar_sensores();

#endif