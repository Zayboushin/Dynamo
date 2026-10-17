// author:leonardo Rodríguez
#ifndef MOTORES_H
#define MOTORES_H

struct motor
{
    byte m1 = 0;
    byte m2 = 0;
    byte pin_pwm = 0;
};

extern struct motor motor_izq_front(m1 : A15, m2 : A14, pin_pwm : 5), motor_izq_back(m1 : A9, m2 : A8, pin_pwm : 2), motor_der_front(m1 : A12, m2 : A13, pin_pwm : 4), motor_der_back(m1 : A10, m2 : A11, pin_pwm : 3), motor_intake(m1 : A0, m2 : A1, pin_pwm : 6);

void iniciar_motores(struct motor &motor_izq_front,
                     struct motor &motor_izq_back,
                     struct motor &motor_der_front,
                     struct motor &motor_der_back,
                     struct motor &motor_intake);

void motor_individual(struct motor &motor, int direction);
void avanzar(byte PWM_izq, byte PWM_der);
void retroceder(byte vel);
void izquierda(byte vel);
void derecha(byte vel);
void detener();
void desp_der(byte vel);
void desp_izq(byte vel);

#endif