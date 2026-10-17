// author:leonardo Rodríguez
#include <Arduino.h>
#include "motores.h"

// Movimiento simple del carrito

// dirección = 1 -> avanzar
// dirección = 0 -> detenerse
// dirección = -1 -> retroceder

extern struct motor motor_izq_front(m1 : A15, m2 : A14, pin_pwm : 5), motor_izq_back(m1 : A9, m2 : A8, pin_pwm : 2), motor_der_front(m1 : A12, m2 : A13, pin_pwm : 4), motor_der_back(m1 : A10, m2 : A11, pin_pwm : 3), motor_intake(m1 : A0, m2 : A1, pin_pwm : 6);

void iniciar_motores(struct motor &motor_izq_front,
                     struct motor &motor_izq_back,
                     struct motor &motor_der_front,
                     struct motor &motor_der_back,
                     struct motor &motor_intake)
{
    // Instancia de los motores (falta declarar pines correctos)
    // pin1, pin2, Pin_pwm
    // funciones de movimiento

    pinMode(motor_izq_front.m1, OUTPUT);
    pinMode(motor_izq_front.m2, OUTPUT);
    pinMode(motor_izq_front.pin_pwm, OUTPUT);

    pinMode(motor_izq_back.m1, OUTPUT);
    pinMode(motor_izq_back.m2, OUTPUT);
    pinMode(motor_izq_back.pin_pwm, OUTPUT);

    pinMode(motor_izq_back.m1, OUTPUT);
    pinMode(motor_izq_back.m2, OUTPUT);
    pinMode(motor_izq_back.pin_pwm, OUTPUT);

    pinMode(motor_der_back.m1, OUTPUT);
    pinMode(motor_der_back.m2, OUTPUT);
    pinMode(motor_der_back.pin_pwm, OUTPUT);
}

void motor_individual(motor &motor, int direction)
{
    analogWrite(motor.pin_pwm, motor.vel);

    // dirección = 1 -> avanzar
    // dirección = 0 -> detenerse
    // dirección = -1 -> retroceder

    switch (direction)
    {
    case 1:
    {
        digitalWrite(motor.m1, HIGH);
        digitalWrite(motor.m2, LOW);
        break;
    }
    case 0:
    {
        digitalWrite(motor.m1, LOW);
        digitalWrite(motor.m2, LOW);
        break;
    }
    case -1:
    {
        digitalWrite(motor.m1, LOW);
        digitalWrite(motor.m2, HIGH);
        break;
    }
    }
}

void avanzar(byte PWM_izq, byte PWM_der)
{
    motor_individual(motor_izq_front, 1);
    analogWrite(motor_izq_front.pin_pwm, PWM_izq);
    motor_individual(motor_izq_back, 1);
    analogWrite(motor_izq_back.pin_pwm, PWM_izq);

    motor_individual(motor_der_front, 1);
    analogWrite(motor_der_front.pin_pwm, PWM_der);
    motor_individual(motor_der_back, 1);
    analogWrite(motor_der_back.pin_pwm, PWM_der);
}

void retroceder(byte vel)
{
    motor_individual(motor_izq_front, -1);
    analogWrite(motor_izq_front.pin_pwm, vel);
    motor_individual(motor_izq_back, -1);
    analogWrite(motor_izq_back.pin_pwm, vel);
    motor_individual(motor_der_front, -1);
    analogWrite(motor_der_front.pin_pwm, vel);
    motor_individual(motor_der_back, -1);
    analogWrite(motor_der_back.pin_pwm, vel);
}

void izquierda(byte vel)
{

    motor_individual(motor_izq_front, -1);
    analogWrite(motor_izq_front.pin_pwm, vel);
    motor_individual(motor_izq_back, -1);
    analogWrite(motor_izq_back.pin_pwm, vel);
    motor_individual(motor_der_front, 1);
    analogWrite(motor_der_front.pin_pwm, vel);
    motor_individual(motor_der_back, 1);
    analogWrite(motor_der_back.pin_pwm, vel);
}

void derecha(byte vel)
{
    motor_individual(motor_izq_front, 1);
    analogWrite(motor_izq_front.pin_pwm, vel);
    motor_individual(motor_izq_back, 1);
    analogWrite(motor_izq_back.pin_pwm, vel);
    motor_individual(motor_der_front, -1);
    analogWrite(motor_der_front.pin_pwm, vel);
    motor_individual(motor_der_back, -1);
    analogWrite(motor_der_back.pin_pwm, vel);
}

void detener()
{
    motor_individual(motor_izq_front, 0);
    analogWrite(motor_izq_front.pin_pwm, 0);
    motor_individual(motor_izq_back, 0);
    analogWrite(motor_izq_back.pin_pwm, 0);
    motor_individual(motor_der_front, 0);
    analogWrite(motor_der_front.pin_pwm, 0);
    motor_individual(motor_der_back, 0);
    analogWrite(motor_der_back.pin_pwm, 0);
}

// Funciones de karla :))

void desp_der(byte vel)
{

    motor_individual(motor_izq_front, 1);
    analogWrite(motor_izq_front.pin_pwm, vel);
    motor_individual(motor_izq_back, -1);
    analogWrite(motor_izq_back.pin_pwm, vel);
    motor_individual(motor_der_front, -1);
    analogWrite(motor_der_front.pin_pwm, vel);
    motor_individual(motor_der_back, 1);
    analogWrite(motor_der_back.pin_pwm, vel);
}

void desp_izq(byte vel)
{
    motor_individual(motor_izq_front, -1);
    analogWrite(motor_izq_front.pin_pwm, vel);
    motor_individual(motor_izq_back, 1);
    analogWrite(motor_izq_back.pin_pwm, vel);
    motor_individual(motor_der_front, 1);
    analogWrite(motor_der_front.pin_pwm, vel);
    motor_individual(motor_der_back, -1);
    analogWrite(motor_der_back.pin_pwm, vel);
}

/*
void encender_intake(uint8_t vel)
{
    motor_intake.motor_individual(1, PWM); // Encender el motor del intake
}
void apagar_intake(uint8_t vel)
{
    motor_intake.motor_individual(0, PWM);
}
    */