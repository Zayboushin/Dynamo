// author:leonardo Rodríguez
#ifndef CONTROL_H
#define CONTROL_H

void iniciar_IMU();

void IMU();

void avanzar_control(float &izq, float &der, float distancia_ultrasonico_izq, float distancia_ultrasonico_der);

bool logica_90grados(bool &giro_pendiente);
#endif