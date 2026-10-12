// author:leonardo Rodríguez

#include <Arduino.h>
#include "sensores.h"

String colores[] = {"azul",
                    "amarillo",
                    "naranja",
                    "rosa",
                    "rojo",
                    "verde",
                    "blanco",
                    "negro"};



// Clase para manejar los sensores ultrasónicos
class ultrasonico
{
private:
    uint8_t trig;
    uint8_t echo;

public:
    ultrasonico()
    {
        trig = 0;
        echo = 0;
    }
    void setPins(uint8_t newTrig, uint8_t newEcho)
    {
        trig = newTrig;
        echo = newEcho;
    }

    void begin()
    {
        pinMode(trig, OUTPUT);
        pinMode(echo, INPUT);
        digitalWrite(trig, LOW);
    }

    float distancia_ultrasonico()
    {
        long t = 0;

        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig, LOW);

        t = pulseIn(echo, HIGH);
        return t / 58.2f; // distancia en cm
    }
};

ultrasonico ultrasonico_izq;
ultrasonico ultrasonico_der;
ultrasonico ultrasonico_frente;

// Función para iniciar los sensores ultrasónicos
class infrarrojo
{
private:
    uint8_t pin;

public:
    infrarrojo()
    {
        pin = 0;
    }
    void setPins(uint8_t newPin)
    {
        pin = newPin;
    }

    void begin()
    {
        pinMode(pin, INPUT);
    }

    // calibrar el sensor infrarrojo para detectar el color blanco y negro

    bool linea_blanca()
    {
        // calibrar el sensor infrarrojo para detectar el color blanco y negro
        bool lectura = digitalRead(pin);

        if (lectura)
        {
            return true; // Devuelve true si detecta blanco
        }
        else
        {
            return false;
        }
    }
};

infrarrojo infrarrojo_izq;
infrarrojo infrarrojo_der;

class RGB
{
private:
    int s0;
    int s1;
    int s2;
    int s3;
    int out;

    int r;
    int v;
    int c;

public:
    RGB()
    {
        s0 = 0;
        s1 = 0;
        s2 = 0;
        s3 = 0;
        out = 0;
    }

    void setPins(int newS0, int newS1, int newS2, int newS3, int newOut)
    {
        s0 = newS0;
        s1 = newS1;
        s2 = newS2;
        s3 = newS3;
        out = newOut;
    }

    void begin()
    {
        pinMode(s0, OUTPUT);
        pinMode(s1, OUTPUT);
        pinMode(s2, OUTPUT);
        pinMode(s3, OUTPUT);
        pinMode(out, INPUT);

        digitalWrite(s0, HIGH);
        digitalWrite(s1, LOW);
    }

    String leer_color()
    {
        // Leer el color del sensor RGB
        digitalWrite(s2, LOW);
        digitalWrite(s3, LOW);
        r = pulseIn(out, LOW);

        digitalWrite(s2, HIGH);
        digitalWrite(s3, HIGH);
        v = pulseIn(out, LOW);

        digitalWrite(s2, LOW);
        digitalWrite(s3, HIGH);
        c = pulseIn(out, LOW);

        // cadena de texto con los valores de los colores (falta agregar forma de detectar el color)
        if (true)
        {
            return colores[0];
        }
        else if (true)
        {
            return colores[1];
        }
        else if (true)
        {
            return colores[2];
        }
        else
        {
            return colores[3];
        }

        return "R: " + String(r) + " V: " + String(v) + " C: " + String(c);
    }
};

RGB sensor_rgb;

// funcion final para iniciación de sensores
void iniciar_sensores()
{
    // Configuración de pines para los sensores ultrasónicos (falta configurarlos)
    ultrasonico_izq.setPins(2, 3);    // Pines del ultrasonico izquierdo
    ultrasonico_der.setPins(4, 5);    // Pines del ultrasonico derecho
    ultrasonico_frente.setPins(6, 7); // Pines del ultrasonico frente
    ultrasonico_izq.begin();
    ultrasonico_der.begin();
    ultrasonico_frente.begin();

    // Configuración de pines para los sensores infrarrojos (falta configurarlos)
    infrarrojo_izq.setPins(8); // Pines del sensor infrarrojo izquierdo
    infrarrojo_der.setPins(9); // Pines del sensor infrarrojo derecho
    infrarrojo_izq.begin();
    infrarrojo_der.begin();

    // Configuración de pines para el sensor RGB (falta configurarlos)
    sensor_rgb.setPins(45, 44, 46, 49, 48); // Pines del sensor RGB
    sensor_rgb.begin();
}

// Karla :)

void navegacion() {
     if (ultrasonico_front < 10 && ultrasonico_der > 50) { //giro a la derecha por pasillo-
        giro_pendiente = true;
        giro_der = true;
        logica_90grados(giro_pendiente);
     }
    else {
        avanzar();
    }
}

void salida1() { //condiciones para salir de secc 1
    if (pelota_tomada && ultrasonico_front >20 && ultrasonico_izq > 40 && ultrasonico_der < 20) {
        giro_pendiente = true;
        giro_izq = true;
        logica_90grados(giro_pendiente);

    }
}

//detectar tonalidad/color

if (rojo == 0 || verde == 0 || azul == 0) return "Desconocido";

    float r =  1000.0 / rojo;
    float g = 1000.0 / verde;
    float b = 1000.0 / azul;

    float mx = max(r, max(g, b));
    float mn = min(r, min(g, b));
    float diferencia = mx - mn;

  // Calcular el tono (0 a 360)
  float tono = 0;
  if (diferencia > 0) { //
    if (mx == r) {    
        tono = 60 * ((g - b) / diferencia);
    }
    else if (mx == g) {     
        tono = 60 * ((b - r) / diferencia + 2);
    }
    else {
        tono = 60 * ((r - g) / diferencia + 4);
    }
    if (tono < 0) {
        tono += 360;
    }
  }
//los numeros son suposiciones, necesito calibrar sensor de color y ajustarlos
  if (tono >= 10 && tono < 35) {
        return "NARANJA";
    } 
    else if (tono >= 35 && tono < 80) {
        return "AMARILLO";
    } 
    else if (tono >= 170 && tono < 260) {
        return "AZUL";
    } 
    else if (tono >= 280 && tono < 345) {
        return "ROSA";
    }
    else {
    return "Desconocido";
    }

    
