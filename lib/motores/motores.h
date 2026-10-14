// author:leonardo Rodríguez
#ifndef MOTORES_H
#define MOTORES_H

void iniciar_motores();

void avanzar(uint8_t PWM_izq, uint8_t PWM_der);

void retroceder(uint8_t PWM);

void izquierda(uint8_t PWM);

void derecha(uint8_t PWM);

void detener();

void giro(int lateralidad);
#endif