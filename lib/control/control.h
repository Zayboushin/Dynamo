// author:leonardo Rodríguez
#ifndef CONTROL_H
#define CONTROL_H

void reiniciar_PID();

void iniciar_IMU();

void calibrar_IMU();

void leer_IMU();

void avanzar_control(float &izq,
                     float &der,
                     float valor_esperado,
                     float valor_actual,
                     byte direccion_giro);

bool logica_90grados(bool &giro_pendiente, String &color);
#endif