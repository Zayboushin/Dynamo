#include <Arduino.h>
#include "sensores/sensores.h"
#include "motores/motores.h"

//Sensores(creo)
#include <WString.h>
long  dist_ultrasonico;
String leer_color;
bool linea_blanca;

void setup

void loop() {

    //Seccion 1

    if (ultrasónico_der > 45) {
    avanzar(200);
    //despues del avanzar lo de abajo se haría si la dist del ultr_der es menor a 45,
    //indicando que es la entrada a la pelota
    detener();
    izquierda(200);//aqui ocupo ponerlo en 90° especif para que el intake tome la pelota
    encender_intake(); //aun no esta esta funcion pero es u ejemplo
    retroceder();

    
else if 
detener()

}


//Salir de seccion 1

    while (ultrasonico_front() >10) { //para salir de donde estaba la pelota
    avanzar(200);
}
detener();

if (ultrasonico_front() >30) {
    while(leer_color() != rojo && ultrasonico_front() >10) { //la funcion leercolor es suposicion junto con rojo porq aun no tenemos esas funciojes
        avanzar(150);
    }
    detener();

else {
    while (ultrasonico_der() >10) { 
        desp_der(200);
    }
    detener();
}

retroceder();
delay(500);

while(ultrasonico_izq() <10 && ultrasonico_der() <10){
    retroceder(200);
}
detener();

if (ultrasonico_izq() >10) {
    while (leer_color() !=rojo) {
        desp_izq(200);
    }
}
    detener();
}
else (ultrasonico_der() >10) {
    while (leer_color() !=rojo) {
        desp_der(200);
    }
    detener();
}


//Seccion 2

if (sensor_rgb.leer_color()== rojo) { //creo q funcionaria para salir de secc 2
    detener();
}
//aqui creo q podria poner el cod de la seccion 3, para no poner whiles

else (infrarojo_izq.hay_blanco() && infrarojo_der.hay_blanco()) {
    detener();
    retroceder(150);
    delay(200);
    detener();
}
else (infrarojo_izq.hay_blanco()) {
    desp_der(200);
}
else (infrarojo_der.hay_blanco()) {
    desp_izq(200);
}
else {
    avanzar(200);
}