#ifndef SENSORES_H
#define SENSORES_H

void setPins(uint8_t newTrig, uint8_t newEcho);

void begin();

float distancia_ultrasonico(ultrasonico);

void iniciar_sensores();
#endif