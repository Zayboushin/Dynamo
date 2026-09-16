#ifndef MOTORES_H
#define MOTORES_H

using namespace std;

void setPins(uint8_t, uint8_t, uint8_t);

void motor_individual(int, uint8_t);

void avanzar(uint8_t PWM_Izq, uint8_t PWM_der);

void retroceder(uint8_t PWM_Izq, uint8_t PWM_der);

void izquierda(uint8_t PWM_Izq, uint8_t PWM_der);

void derecha(uint8_t, uint8_t);

void detener();

#endif