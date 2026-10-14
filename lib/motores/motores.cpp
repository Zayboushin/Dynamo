// author:leonardo Rodríguez
#include <Arduino.h>
#include "motores.h"

// Movimiento simple del carrito

// dirección = 1 -> avanzar
// dirección = 0 -> detenerse
// dirección = -1 -> retroceder

motor motor_izq_front, motor_izq_back, motor_der_front, motor_der_back, motor_intake;

void iniciar_motores()
{
    // Instancia de los motores (falta declarar pines correctos)

    motor_izq_front.setPins(2, 3, 4);
    motor_izq_back.setPins(5, 6, 7);
    motor_der_front.setPins(8, 9, 10);
    motor_der_back.setPins(11, 12, 13);
    motor_intake.setPins(A0, A1, 6);
    // funciones de movimiento

    motor_der_back.begin();  // Pines del motor derecho trasero
    motor_der_front.begin(); // Pines del motor derecho delantero
    motor_izq_front.begin(); // Pines del motor izquierdo delantero
    motor_izq_back.begin();  // Pines del motor izquierdo trasero
    motor_intake.begin();     // Pines del motor del intake
}

void avanzar(uint8_t PWM_izq, uint8_t PWM_der)
{
    motor_izq_front.motor_individual(1, PWM_izq);
    motor_izq_back.motor_individual(1, PWM_izq);
    motor_der_front.motor_individual(1, PWM_der);
    motor_der_back.motor_individual(1, PWM_der);
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

void giro(int lateralidad)
{
    // funciones a calibrar para que de un giro limpio
    uint8_t PWM_menor = 50;
    uint8_t PWM_mayor = 150;
    if (lateralidad == 1)
    {
        motor_izq_front.motor_individual(1, PWM_menor);
        motor_izq_back.motor_individual(1, PWM_menor);
        motor_der_front.motor_individual(1, PWM_mayor);
        motor_der_back.motor_individual(1, PWM_mayor);
    }
    else if (lateralidad == 2)
    {
        motor_izq_front.motor_individual(1, PWM_mayor);
        motor_izq_back.motor_individual(1, PWM_mayor);
        motor_der_front.motor_individual(1, PWM_menor);
        motor_der_back.motor_individual(1, PWM_menor);
    }
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

//pines del driver del intake y limit switch
 const uint8_t PIN_STBY = A2;
 const uint8_t LIMIT_SWITCH = 12;

void encender_intake(uint8_t PWM)
{
    motor_intake.motor_individual(1, PWM); // Encender el motor del intake 
}
void apagar_intake(uint8_t PWM) {
    motor_intake.motor_individual(0, PWM);
}

//limit switch
bool limit_switch() {
    return digitalRead(LIMIT_SWITCH) == LOW; // Devuelve true si el limit switch está activado (LOW)
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
