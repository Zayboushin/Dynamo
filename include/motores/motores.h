#ifndef MOTORES_H
#define MOTORES_H

using namespace std;

void setPins(uint8_t pin1, uint8_t pin2, uint8_t newPin_pwm);

void begin();

void motor_individual(int dir, uint8_t vel);

void iniciar_motores();

void avanzar(uint8_t PWM);

void retroceder(uint8_t PWM);

void izquierda(uint8_t PWM);

void derecha(uint8_t PWM);

void detener();

#endif