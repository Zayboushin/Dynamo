// author:leonardo Rodríguez
#include <Arduino.h>
#include "motores.h"

// Movimiento simple del carrito

// dirección = 1 -> avanzar
// dirección = 0 -> detenerse
// dirección = -1 -> retroceder

struct motor motor_izq_back = {A9, A8, 2};
struct motor motor_izq_front = {A7, A6, 1};
struct motor motor_der_front = {A12, A13, 4};
struct motor motor_der_back = {A10, A11, 3};

void iniciar_motores()
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

void motor_individual(motor &m, int direction)
{

    // dirección = 1 -> avanzar
    // dirección = 0 -> detenerse
    // dirección = -1 -> retroceder

    switch (direction)
    {
    case 1:
    {
        digitalWrite(m.m1, HIGH);
        digitalWrite(m.m2, LOW);
        break;
    }
    case 0:
    {
        digitalWrite(m.m1, LOW);
        digitalWrite(m.m2, LOW);
        break;
    }
    case -1:
    {
        digitalWrite(m.m1, LOW);
        digitalWrite(m.m2, HIGH);
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