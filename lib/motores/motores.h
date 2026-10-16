// author:leonardo Rodríguez
#ifndef MOTORES_H
#define MOTORES_H

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
        case 1:
        {
            digitalWrite(m1, HIGH);
            digitalWrite(m2, LOW);
            break;
        }
        case 0:
        {
            digitalWrite(m1, LOW);
            digitalWrite(m2, LOW);
            break;
        }
        case -1:
        {
            digitalWrite(m1, LOW);
            digitalWrite(m2, HIGH);
            break;
        }
        }
    }
};

extern motor motor_izq_front, motor_izq_back, motor_der_front, motor_der_back, motor_intake;

void iniciar_motores();

void avanzar(uint8_t PWM_izq, uint8_t PWM_der);

void retroceder(uint8_t PWM);

void izquierda(uint8_t PWM);

void derecha(uint8_t PWM);

void detener();

void giro(byte lateralidad);

void desp_der(uint8_t PWM);

void desp_izq(uint8_t PWM);
#endif