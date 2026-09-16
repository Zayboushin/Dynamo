#include <stdint.h>
#include <Arduino.h>

// Movimiento simple del carrito

// dirección = 1 -> avanzar
// dirección = 0 -> detenerse
// dirección = -1 -> retroceder

void motor_izq_frente(uint8_t pin_pwm, uint8_t A1, uint8_t A2, int dir, uint8_t pwm)
{
    analogWrite(pin_pwm, pwm);

    // dirección = 1 -> avanzar
    // dirección = 0 -> detenerse
    // dirección = -1 -> retroceder

    switch (dir)
    {
    case -1:
    {
        digitalWrite(A1, LOW);
        digitalWrite(A2, HIGH);
    }
    case 0:
    {
        digitalWrite(A1, LOW);
        digitalWrite(A2, LOW);
    }
    case 1:
    {
        digitalWrite(A1, HIGH);
        digitalWrite(A2, LOW);
    }
    }
}

funcion control_motor_der(dirección)
// dirección = 1 -> avanzar
// dirección = 0 -> detenerse
// dirección = -1 -> retroceder
FinFuncion

    funcion
    avanzar(PWM_Izq, PWM_der)
        control_motor_izq(1, PWM_Izq)
            control_motor_der(1, PWM_der)
                FinFuncion

    funcion giro(lateralidad, PWM_Izq, PWM_der)
si lateralidad == 1 control_motor_izq(-1, PWM_Izq) control_motor_der(1, PWM_der) FinSi si lateralidad == 2 control_motor_izq(1, PWM_Izq) control_motor_der(-1, PWM_der) FinSi

    FinFuncion

    funcion detener() control_motor_izq(0) control_motor_der(0) FinFuncion

    Funcion giro90(lateralidad_elegida, giro_pendiente, posiciones x y z) Si(giro_pendiente y no ha girado 90 % -el giro se define con las posiciones guardadas en la condicion anterior -)

        giro(lateralidad_elegida, vel, vel)

            FinSi

    FinFuncion
