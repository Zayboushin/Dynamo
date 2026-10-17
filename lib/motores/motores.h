#include <Arduino.h>

// author:leonardo Rodríguez
#ifndef MOTORES_H
#define MOTORES_H

struct motor
{
    byte m1 = 0;
    byte m2 = 0;
    byte pin_pwm = 0;
};

extern motor motor_izq_front, motor_izq_back, motor_der_front, motor_der_back, motor_intake;

void iniciar_motores(struct motor &motor_izq_front,
                     struct motor &motor_izq_back,
                     struct motor &motor_der_front,
                     struct motor &motor_der_back,
                     struct motor &motor_intake);

void motor_individual(struct motor &m, int direction);
void avanzar(byte PWM_izq, byte PWM_der);
void retroceder(byte vel);
void izquierda(byte vel);
void derecha(byte vel);
void detener();
void desp_der(byte vel);
void desp_izq(byte vel);

#endif