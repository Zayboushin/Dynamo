#include <Arduino.h>
#include "motores.h"

// Movimiento simple del carrito

// dirección = 1 -> avanzar
// dirección = 0 -> detenerse
// dirección = -1 -> retroceder

class motor
{
private:
    uint8_t m1;
    uint8_t m2;
    uint8_t pin_pwm;
    int dir;
    uint8_t vel;

public:
    // sigo sin entender como funcionan los constructores, pero por ahora lo dejo asi
    motor()
    {
        m1 = 0;
        m2 = 0;
        pin_pwm = 0;
        dir = 0;
        vel = 0;
    }

    void setPins(uint8_t pin1, uint8_t pin2, uint8_t newPin_pwm)
    {
        m1 = pin1;
        m2 = pin2;
        pin_pwm = newPin_pwm;
    }

    void begin()
    {
        pinMode(m1, OUTPUT);
        pinMode(m2, OUTPUT);
        pinMode(pin_pwm, OUTPUT);
    }

    void motor_individual(int dir, uint8_t vel)
    {
        analogWrite(pin_pwm, vel);

        // dirección = 1 -> avanzar
        // dirección = 0 -> detenerse
        // dirección = -1 -> retroceder

        switch (dir)
        {
        case -1:
        {
            digitalWrite(m1, LOW);
            digitalWrite(m2, HIGH);
            break;
        }
        case 0:
        {
            digitalWrite(m1, LOW);
            digitalWrite(m2, LOW);
            break;
        }
        case 1:
        {
            digitalWrite(m1, HIGH);
            digitalWrite(m2, LOW);
            break;
        }
        }
    }
};

motor motor_izq_front, motor_izq_back, motor_der_front, motor_der_back;

void iniciar_motores()
{
    // Instancia de los motores (falta declarar pines correctos)

    motor_izq_front.setPins(2, 3, 4);
    motor_izq_back.setPins(5, 6, 7);
    motor_der_front.setPins(8, 9, 10);
    motor_der_back.setPins(11, 12, 13);
    // funciones de movimiento

    motor_der_back.begin();  // Pines del motor derecho trasero
    motor_der_front.begin(); // Pines del motor derecho delantero
    motor_izq_front.begin(); // Pines del motor izquierdo delantero
    motor_izq_back.begin();  // Pines del motor izquierdo trasero
}

void avanzar(uint8_t PWM)
{
    motor_izq_front.motor_individual(1, PWM);
    motor_izq_back.motor_individual(1, PWM);
    motor_der_front.motor_individual(1, PWM);
    motor_der_back.motor_individual(1, PWM);
}

void retroceder(uint8_t PWM)
{
    motor_izq_front.motor_individual(-1, PWM);
    motor_izq_back.motor_individual(-1, PWM);
    motor_der_front.motor_individual(-1, PWM);
    motor_der_back.motor_individual(-1, PWM);
}

void izquierda(uint8_t PWM)
{
    motor_izq_front.motor_individual(-1, PWM);
    motor_izq_back.motor_individual(-1, PWM);
    motor_der_front.motor_individual(1, PWM);
    motor_der_back.motor_individual(1, PWM);
}

void derecha(uint8_t PWM)
{
    motor_izq_front.motor_individual(1, PWM);
    motor_izq_back.motor_individual(1, PWM);
    motor_der_front.motor_individual(-1, PWM);
    motor_der_back.motor_individual(-1, PWM);
}

void detener()
{
    motor_izq_front.motor_individual(0, 0);
    motor_izq_back.motor_individual(0, 0);
    motor_der_front.motor_individual(0, 0);
    motor_der_back.motor_individual(0, 0);
}

//Funciones de karla :))

void desp_der(uint8_t PWM)
{
    motor_izq_front.motor_individual(1, PWM);
    motor_izq_back.motor_individual(-1, PWM);
    motor_der_front.motor_individual(-1, PWM);
    motor_der_back.motor_individual(1, PWM);
}

void desp_izq(uint8_t PWM)
{
    motor_izq_front.motor_individual(-1, PWM);
    motor_izq_back.motor_individual(1, PWM);
    motor_der_front.motor_individual(1, PWM);
    motor_der_back.motor_individual(-1, PWM);
}

/*



funcion giro(lateralidad, PWM_Izq, PWM_der)
si lateralidad == 1 control_motor_izq(-1, PWM_Izq) control_motor_der(1, PWM_der) FinSi si lateralidad == 2 control_motor_izq(1, PWM_Izq) control_motor_der(-1, PWM_der) FinSi

    FinFuncion

    funcion detener() control_motor_izq(0) control_motor_der(0) FinFuncion

    Funcion giro90(lateralidad_elegida, giro_pendiente, posiciones x y z) Si(giro_pendiente y no ha girado 90 % -el giro se define con las posiciones guardadas en la condicion anterior -)

        giro(lateralidad_elegida, vel, vel)

            FinSi

    FinFuncion
*/