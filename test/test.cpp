#include <Arduino.h>
#include <Wire.h>

void setup()
{
    Serial.begin(115200);
    Wire.begin();
    for (uint8_t dir = 1; dir < 127; dir++)
    {
        Wire.beginTransmission(dir);
        if (Wire.endTransmission() == 0)
        {
            Serial.print("Dispositivo en 0x");
            Serial.println(dir, HEX);
        }
    }
    Serial.println("Escaneo terminado");
}

void loop() {}