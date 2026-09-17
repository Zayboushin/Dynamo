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
ultrasonico ultrasonico_izq;
ultrasonico ultrasonico_der;
ultrasonico ultrasonico_frente;

class infrarrojo
{
private:
    uint8_t pin;

public:
    infrarrojo();
    void setPins(uint8_t newPin);
    void begin();
    bool hay_blanco();
};

infrarrojo infrarrojo_izq;
infrarrojo infrarrojo_der;

void iniciar_sensores();

#endif