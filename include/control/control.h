#ifndef CONTROL_H
#define CONTROL_H

void begin();

void activacion_IMU();
list<float> avanzar_control(float distancia_ultrasonico_izq, float distancia_ultrasonico_der);
bool logica_90grados(bool &giro_pendiente);

#endif