// author:leonardo Rodríguez
//  librería para PID con ultrasonicos y giro con IMU

#include <Arduino.h>
#include "control.h"
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 IMU;

//valores de PID random (por calibrar)
const float P = 4.0f;            
const float I = 0.5f;
const float D = 0.3f;

//variable de movimiento
const float vel = 180.0f;

//variables importantes para I 
const float limite_I = 30.0f;     
const float zona_I   = 6.0f; 
static float integral = 0.0f;

//variables importantes para registro de error
static float error_anterior = 0.0f;
static unsigned long antes_ms = 0;

sensors_event_t a, g, temp;

void iniciar_IMU()
{
    while (!Serial)
        delay(10);
    if (!IMU.begin())
    {
        Serial.println("Failed to find MPU6050 chip");
        while (1)
            delay(10);
    }
}

void leer_IMU()
{
    IMU.getEvent(&a, &g, &temp);

    // Retorna la aceleración en el eje X

}

void reiniciar_PID()
{
    integral = 0.0f;
    error_anterior = 0.0f;
    antes_ms = 0;
}

void avanzar_control(float &izq, float &der, float distancia_ultrasonico_izq, float distancia_ultrasonico_der)
{
    unsigned long ahora = millis();
    bool primera = (antes_ms == 0);
    float dt = (ahora - antes_ms) / 1000.0f;
    antes_ms = ahora;
    
    float error = constrain((distancia_ultrasonico_izq - distancia_ultrasonico_der), -20.0f, 20.0f);

    // P
    float termino_p = P * error;

    // I

    if (!primera && fabs(error) < zona_I)
    {
        integral += I*error*dt;
        integral = constrain(integral, -limite_I, limite_I);

    }

    // D

    float termino_d = 0.0f;
    if (!primera && dt > 0.0f)
        termino_d = D * (error - error_anterior) / dt;
    error_anterior = error;

    float correccion = termino_p + integral + termino_d;


    izq = constrain(vel - correccion, 0.0f, 255.0f);
    der = constrain(vel + correccion, 0.0f, 255.0f);
}

bool logica_90grados(bool &giro_pendiente)
{
    static float grados_x = 0;
    static float grados_y = 0;
    static float grados_z = 0;
    static long antes = 0;
    static long segundos = 0;

    leer_IMU();

    long ahora = millis();

    if (antes == 0)
    {
        segundos = 0;
    }
    else
    {
        segundos = (ahora - antes) / 1000.0f;
    }

    antes = ahora;

    grados_x += g.gyro.x * segundos;
    grados_y += g.gyro.y * segundos;
    grados_z += g.gyro.z * segundos;

    // funcion que determina que se detenga el giro
    if (grados_x >= 3.14159 / 2)
    {
        // indica que ya se pasó del giro de 90 grados, deteniendo el uso de esta funcion

        //
        grados_x = 0;
        grados_y = 0;
        grados_z = 0;
        giro_pendiente = false;
        return giro_pendiente;
    }
    else
    {
        return true;
    }
}