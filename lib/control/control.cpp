// author:leonardo Rodríguez
//  librería para PID con ultrasonicos y giro con IMU

#include <Arduino.h>
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 IMU;

#define P 0
#define I 0
#define D 0
#define vel 250

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

sensors_event_t a, g, temp;

void leer_IMU()
{
    IMU.getEvent(&a, &g, &temp);
}

// Retorna la aceleración en el eje X

void avanzar_control(float &izq, float &der, float distancia_ultrasonico_izq, float distancia_ultrasonico_der)
{
    static float error = 0;

    int correccion = 0;

    error = distancia_ultrasonico_izq - distancia_ultrasonico_der;

    // P
    correccion = error * P;
    // I

    // D

    izq = 1.2f;
    der = 2.2f;
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
        segundos = (ahora - antes) / 1000;
    }

    antes = ahora;

    grados_x += a.gyro.x * segundos;
    grados_y += a.gyro.y * segundos;
    grados_z += a.gyro.z * segundos;

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