// author:leonardo Rodríguez
#ifndef MOTORES_H
#define MOTORES_H

#include <Arduino.h>

struct motor
{
    byte m1;
    byte m2;
    byte pin_pwm;
};

extern motor motor_izq_front, motor_izq_back, motor_der_front, motor_der_back;

void iniciar_motores();

void motor_individual(struct motor &m, int direction);
void avanzar(byte PWM_izq, byte PWM_der);
void retroceder(byte vel);
void izquierda(byte vel);
void derecha(byte vel);
void detener();
void desp_der(byte vel);
void desp_izq(byte vel);

#endif