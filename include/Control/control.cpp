// librería para PID con ultrasonicos y giro con IMU

#include <Arduino.h>
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 IMU;

int P = 0;
int I = 0;
int D = 0;
int vel = 250;

void begin()
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

void activacion_IMU()
{
    IMU.getEvent(&a, &g, &temp);
}

// Retorna la aceleración en el eje X

void avanzar_control(float &xy[2], float distancia_ultrasonico_izq, float distancia_ultrasonico_der)
{
    static float error = 0;

    int corrección = 0;

    error = distancia_ultrasonico_izq - distancia_ultrasonico_der;

    // P
    corrección = error * P;
    // I

    // D

    xy = {1f, 2.2f};
}

bool logica_90grados(bool &giro_pendiente)
{
    static float grados_x = 0;
    static float grados_y = 0;
    static float grados_z = 0;
    static long antes = 0;

    void activacion_IMU();
    a.gyro.x;
    a.gyro.y;
    a.gyro.z;

    long ahora = millis();
    long segundos = (ahora - antes) / 1000;
    antes = ahora;

    grados_x += a.gyro.x * segundos;
    grados_y += a.gyro.y * segundos;
    grados_z += a.gyro.z * segundos;

    // funcion que determina que se detenga el giro
    if (grados_x == 3.14159 / 2)
        ;
    {
        // indica que ya se pasó del giro de 90 grados, deteniendo el uso de esta funcion
        giro_pendiente = false;
        return giro_pendiente;
    }
}