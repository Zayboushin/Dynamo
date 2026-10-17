// author:leonardo Rodríguez
//  librería para PID con ultrasonicos y giro con IMU

#include <Wire.h>
#include <Arduino.h>
#include "control.h"
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 IMU;
static const uint8_t IMU_ADDR = 0x68;

// valores de PID random (por calibrar)
const float P = 4.0f;
const float I = 0.5f;
const float D = 0.3f;

// variable de movimiento
const float vel = 67.0f;

// variables importantes para I
const float limite_I = 30.0f;
const float zona_I = 6.0f;
static float integral = 0.0f;

// variables importantes para registro de error
static float error_anterior = 0.0f;
static unsigned long antes_ms = 0;

sensors_event_t a, g, temp;

void iniciar_IMU()
{
    Wire.begin();
    IMU.begin(0x68);
    IMU.setGyroRange(MPU6050_RANGE_500_DEG); // ±500 °/s es suficiente para un carro
    IMU.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

static float sesgo_x = 0.0f;
static float sesgo_y = 0.0f;
static float sesgo_z = 0.0f;

void calibrar_IMU()
{
    float suma_x = 0.0f;
    float suma_y = 0.0f;
    float suma_z = 0.0f;
    for (int i = 0; i < 200; i++)
    {
        IMU.getEvent(&a, &g, &temp);
        suma_x += g.gyro.x;
        suma_y += g.gyro.y;
        suma_z += g.gyro.z;
        delay(5);
    }
    sesgo_x = suma_x / 200.0f;
    sesgo_y = suma_y / 200.0f;
    sesgo_z = suma_z / 200.0f;
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

void avanzar_control(float &izq,
                     float &der,
                     float valor_esperado,
                     float valor_actual,
                     byte direccion_giro)

{
    unsigned long ahora = millis();
    bool primera = (antes_ms == 0);
    float dt = (ahora - antes_ms) / 1000.0f;
    antes_ms = ahora;

    float error = constrain((valor_esperado - valor_actual), -20.0f, 20.0f);

    // P
    float termino_p = P * error;

    // I

    if (!primera && fabs(error) < zona_I)
    {
        integral += I * error * dt;
        integral = constrain(integral, -limite_I, limite_I);
    }

    // D

    float termino_d = 0.0f;
    if (!primera && dt > 0.0f)
        termino_d = D * (error - error_anterior) / dt;
    error_anterior = error;

    float correccion = termino_p + integral + termino_d;

    if (direccion_giro == 1) // giro a la izquierda
    {
        izq = constrain(vel + correccion, 0.0f, 255.0f);
        der = constrain(vel - correccion, 0.0f, 255.0f);
    }
    else if (direccion_giro == 2) // giro a la derecha
    {
        izq = constrain(vel - correccion, 0.0f, 255.0f);
        der = constrain(vel + correccion, 0.0f, 255.0f);
    }
    else // no hay giro, se mueve recto
    {
        izq = vel;
        der = vel;
    }
}

bool logica_90grados(bool &giro_pendiente)
{
    static float grados_x = 0;
    static float grados_y = 0;
    static float grados_z = 0;
    static byte primer_iteracion = 1;
    static float tiempo_seguridad = 0.0f;
    unsigned static long antes = 0;

    leer_IMU();

    if (primer_iteracion == 1)
    {
        tiempo_seguridad = millis();
    }
    unsigned long ahora = millis();

    float dt = 0.0f;
    if (antes == 0)
    {
        dt = 0.0f;
    }
    else
    {
        dt = (ahora - antes) / 1000.0f;
    }

    antes = ahora;

    grados_x += (g.gyro.x - sesgo_x) * dt;
    grados_y += (g.gyro.y - sesgo_y) * dt;
    grados_z += (g.gyro.z - sesgo_z) * dt;

    // funcion que determina que se detenga el giro
    if (fabs(grados_z) >= 0.95 * PI / 2 || (ahora - tiempo_seguridad) > 2000)
    {
        // indica que ya se pasó del giro de 90 grados, deteniendo el uso de esta funcion

        //
        grados_x = 0;
        grados_y = 0;
        grados_z = 0;
        giro_pendiente = false;
        antes = 0;
        return giro_pendiente;
    }
    else
    {
        return true;
    }
    {
        // indica que ya se pasó del giro de 90 grados, deteniendo el uso de esta funcion

        //
        grados_x = 0;
        grados_y = 0;
        grados_z = 0;
        giro_pendiente = false;
        antes = 0;
        return giro_pendiente;
    }
    else
    {
        return true;
    }
}