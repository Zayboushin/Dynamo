#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>

Adafruit_MPU6050 mpu;

void setup()
{
  Serial.begin(115200);
  Wire.begin();

  if (!mpu.begin(0x68, &Wire))
  {
    Serial.println("No se encontro el MPU6050");
    while (true)
      delay(10);
  }

  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("IMU listo");
}

void loop()
{
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  Serial.print("Gyro (rad/s)  x: ");
  Serial.print(g.gyro.x, 2);
  Serial.print("  y: ");
  Serial.print(g.gyro.y, 2);
  Serial.print("  z: ");
  Serial.print(g.gyro.z, 2);

  Serial.print("   |   Accel (m/s2)  x: ");
  Serial.print(a.acceleration.x, 2);
  Serial.print("  y: ");
  Serial.print(a.acceleration.y, 2);
  Serial.print("  z: ");
  Serial.println(a.acceleration.z, 2);

  delay(200);
}