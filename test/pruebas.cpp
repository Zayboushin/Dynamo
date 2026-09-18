#include <Arduino.h>
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 IMU;

IMU.begin();

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        delay(10);
}