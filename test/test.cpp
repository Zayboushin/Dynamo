// author: prueba de ultrasónicos — usa la librería sensores del repo
// Pegar en test/test.cpp. No mueve los motores.
//
// Monitor serial a 115200.
//   Modo normal : imprime izq / der / frente cada ~150 ms
//   Enviar "e"  : estadísticas (20 lecturas por sensor: mín, máx, promedio, sin eco)
//   Enviar "p"  : pausar / reanudar la impresión

#include <Arduino.h>
#include "sensores.h"

// Mismos umbrales que pistaA.cpp (cámbialos aquí para probar otros)
const float UMBRAL_LATERAL = 15.0f; // choque_lateral_inminente
const float UMBRAL_FRONTAL = 10.0f; // choque_frontal_inminente

const unsigned long PERIODO_MS = 150;
const unsigned long ESPERA_ENTRE_SENSORES_MS = 30; // deja morir el eco antes del siguiente

bool pausado = false;
unsigned long ultima_impresion = 0;

// Una lectura con espera después, para que un sensor no oiga el eco del anterior
float leer(ultrasonico &u)
{
  float d = u.distancia_ultrasonico();
  delay(ESPERA_ENTRE_SENSORES_MS);
  return d;
}

// La librería devuelve 0 cm cuando no hay eco (pulseIn agota el tiempo).
// pistaA lo interpreta como "pared pegada".
bool sin_eco(float d) { return d <= 0.0f; }

void imprimir_sensor(const char *nombre, float d, float umbral)
{
  Serial.print(nombre);
  Serial.print(": ");
  if (sin_eco(d))
  {
    Serial.print("SIN ECO (pistaA: PARED)");
  }
  else
  {
    Serial.print(d, 1);
    Serial.print(" cm ");
    Serial.print(d < umbral ? "[PARED]" : "[libre]");
  }
}

void estadisticas()
{
  const int N = 20;
  ultrasonico *sensores[3] = {&ultrasonico_izq, &ultrasonico_der, &ultrasonico_frente};
  const char *nombres[3] = {"izq", "der", "frente"};

  Serial.println(F("--- estadisticas (20 lecturas, deja el carrito quieto) ---"));
  for (int s = 0; s < 3; s++)
  {
    float minimo = 1000.0f, maximo = 0.0f, suma = 0.0f;
    int validas = 0, sin_eco_n = 0;

    for (int i = 0; i < N; i++)
    {
      float d = leer(*sensores[s]);
      if (sin_eco(d))
      {
        sin_eco_n++;
      }
      else
      {
        validas++;
        suma += d;
        if (d < minimo)
          minimo = d;
        if (d > maximo)
          maximo = d;
      }
      delay(40);
    }

    Serial.print(nombres[s]);
    Serial.print(": ");
    if (validas > 0)
    {
      Serial.print("min ");
      Serial.print(minimo, 1);
      Serial.print("  max ");
      Serial.print(maximo, 1);
      Serial.print("  prom ");
      Serial.print(suma / validas, 1);
      Serial.print("  (dispersion ");
      Serial.print(maximo - minimo, 1);
      Serial.print(" cm)");
    }
    Serial.print("  sin eco: ");
    Serial.print(sin_eco_n);
    Serial.print("/");
    Serial.println(N);
  }
  Serial.println(F("--- fin ---"));
}

void setup()
{
  Serial.begin(9600);
  iniciar_sensores(); // usa los pines definidos en sensores.cpp

  Serial.println(F("Prueba de ultrasonicos. 'e' = estadisticas, 'p' = pausar"));
  Serial.print(F("Umbral lateral: "));
  Serial.print(UMBRAL_LATERAL, 0);
  Serial.print(F(" cm | frontal: "));
  Serial.print(UMBRAL_FRONTAL, 0);
  Serial.println(F(" cm"));
}

void loop()
{
  while (Serial.available())
  {
    char c = Serial.read();
    if (c == 'e')
      estadisticas();
    else if (c == 'p')
    {
      pausado = !pausado;
      Serial.println(pausado ? F("[pausado]") : F("[reanudado]"));
    }
  }

  if (pausado || millis() - ultima_impresion < PERIODO_MS)
    return;
  ultima_impresion = millis();

  float d_izq = leer(ultrasonico_izq);
  float d_der = leer(ultrasonico_der);
  float d_frente = leer(ultrasonico_frente);

  imprimir_sensor("izq", d_izq, UMBRAL_LATERAL);
  Serial.print(" | ");
  imprimir_sensor("der", d_der, UMBRAL_LATERAL);
  Serial.print(" | ");
  imprimir_sensor("frente", d_frente, UMBRAL_FRONTAL);
  Serial.println();
}