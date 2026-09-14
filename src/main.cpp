#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

void setup()
{
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y)
{
  return x + y;
}

/*


// Primer pista
vector<String> posiciones_avance;

// variables para reto
//  “left” = “izquierda”
//  “right” = “derecha”
//  “up” = “arriba”
//  “down” = “abajo”




//variables de control
P = ?
I = ?
D = ?
vel = 250

//logica
bool giro_pendiente = false

int lateralidad = 0
//izquierda = 1
//derecha = 2

cercania_pared = 5 //valor que define que tan cerca estara de la pared una vez se defina la lateralidad. revisar que valor es mejor

choque_inminente = 15 //distancia en donde se detecta que hay una pared

//inicio de funciones
//Movimiento simple del carrito
funcion control_motor_izq(dirección,PWM)
  //dirección = 1 -> avanzar
  //dirección = 0 -> detenerse
//dirección = -1 -> retroceder
FinFuncion

funcion control_motor_der(dirección)
  //dirección = 1 -> avanzar
  //dirección = 0 -> detenerse
//dirección = -1 -> retroceder
FinFuncion

funcion avanzar(PWM_Izq, PWM_der)
  control_motor_izq(1, PWM_Izq)
  control_motor_der(1, PWM_der)
FinFuncion

funcion giro(lateralidad, PWM_Izq, PWM_der)
si lateralidad == 1
  control_motor_izq(-1, PWM_Izq)
  control_motor_der(1, PWM_der)
FinSi
si lateralidad == 2
  control_motor_izq(1, PWM_Izq)
  control_motor_der(-1, PWM_der)
FinSi

FinFuncion

funcion detener()
  control_motor_izq(0)
  control_motor_der(0)
FinFuncion

Funcion giro90 (lateralidad_elegida, giro_pendiente, posiciones x y z)
  Si (giro_pendiente y no ha girado 90% -el giro se define con las posiciones guardadas en la condicion anterior- )

giro(lateralidad_elegida, vel, vel)

FinSi

FinFuncion

//Sensores
Funcion long distancia_ultrasonico(ultrasonico)
  //De entrada, se recibe uno de los 3 ultrasónicos (enfrente, izquierda, derecha)

FinFuncion

Funcion correcion_drift()
//Lectura de sensores
//establecimiento de lecturas como “recto”
FinFuncion

Funcion lectura_IMU()
FinFuncion

Funcion lectura_RGB(valores del pin)
  colorea el LED si el rango de colores está en los establecidos
FinFuncion
// Lógica
funcion boolenana pared(ultrasonico)
  //De entrada, se recibe uno de los 3 ultrasónicos (enfrente, izquierda, derecha)
  //se ingresa la lateralidad para determinar cual de estos checar.
  long distancia_ultrasonico(ultrasonico)
  Si distancia_ultrasonico < choque_inminente

  devolver verdadero
SiNo
  devolver falso

FinFuncion
  hay que tener cuidado con la distancia y la posición del ultrasónico, para que no detecte las escaleras como paredes. Ultrasónico 5.5 cm arriba del suelo

Funcion calibracion(valor sensor izquierdo, valor sensor derecho)
corrección = 0
double error = 0
Si lateralidad == 0
  double error = valor sensor izquierdo - valor sensor derecho

SiNo
switch lateralidad
    //revisar logica detras de la dirección: los signos son muy importantes
case 1:
    double error = valor sensor izquierdo - cercania_pared

  case 2:
        double error = cercania_pared - valor sensor derecho


FinSi

//P
  correccion= error*P

//I
  //D

devolver correccion

FinFuncion

void loop ()

  //bloque para definir lateralidad
Si lateralidad == 0
    Si !pared(Ultrasónico izquierdo)
      lateralidad = 1
    FinSi

Si !pared(Ultrasónico derecho)
    lateralidad = 2
    FinSi
  FinSi


  //seccion que permite que el carrito vaya recto en las partes donde no gira
Si (!giro_pendiente)

HC_izq = distancia_ultrasonico(Ultrasónico izquierdo)
HC_der = distancia_ultrasonico(Ultrasónico derecho)

corrección = calibracion(lateridad, HC_izq, HC_der)
//regresa los valores de corrección para determinar el PWM final del motor

avanzar(vel - corrección, vel + corrección)
  //revisar signos

correcion_drift()
  FinSi

  //la logica aqui es que el carrito no gira hasta que topa con una pared de frente o no detecta una pared del lado de su lateralidad.

//pared(lateridad) -Esta ultima funcion necesita cambios para poder aceptar el valor de lateralidad-

//Funcion giro90 (lateralidad_elegida, giro_pendiente, posiciones x y z)

Si pared(enfrente)
Si !giro_pendiente
definir posiciones x y z
FinSi
giro_pendiente = true

Si pared(lateridad))
  Si lateralidad == 1
    lateralidad_elegida = 2
Sino
Si lateralidad == 2
      lateralidad_elegida = 1


    FinSi
    FinSi
SiNo
Si !pared(lateridad)
  lateralidad_elegida = lateralidad
FinSi

FinSi

  giro90(lateralidad_elegida, giro_pendiente, posiciones x y z)

lectura_RGB(valores del pin)



FinVoid


//corregir lógica: hay un problema con el guardado de posiciones. pasar esa logica a la funcion de giro90


*/