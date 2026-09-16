#include <stdint.h>
#include <Arduino.h>

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
    motor()
    {
        m1 = 0;
        m2 = 0;
        pin_pwm = A0;
        dir = 0;
        vel = 0;
    }

    void setPins(uint8_t newM1, uint8_t newM2, uint8_t newPin_pwm)
    {
        m1 = newM1;
        m2 = newM2;
        pin_pwm = newPin_pwm;
    }

    void setDir(int newDir)
    {
        dir = newDir;
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

            digitalWrite(m1, LOW);
            digitalWrite(m2, HIGH);
            break;
        case 0:
            digitalWrite(m1, LOW);
            digitalWrite(m2, LOW);
            break;
        case 1:
            digitalWrite(m1, HIGH);
            digitalWrite(m2, LOW);
            break;
        }
    }
};

funcion giro(lateralidad, PWM_Izq, PWM_der)
si lateralidad == 1 control_motor_izq(-1, PWM_Izq) control_motor_der(1, PWM_der) FinSi si lateralidad == 2 control_motor_izq(1, PWM_Izq) control_motor_der(-1, PWM_der) FinSi

    FinFuncion

    funcion detener() control_motor_izq(0) control_motor_der(0) FinFuncion

    Funcion giro90(lateralidad_elegida, giro_pendiente, posiciones x y z) Si(giro_pendiente y no ha girado 90 % -el giro se define con las posiciones guardadas en la condicion anterior -)

        giro(lateralidad_elegida, vel, vel)

            FinSi

    FinFuncion
