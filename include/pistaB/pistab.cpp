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
    if(leer_color() != rojo && ultrasonico_front() >10) { //la funcion leercolor es suposicion junto con rojo porq aun no tenemos esas funciojes
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

//parte seccion 2


void eleccion_desplazamiento(string direccion) {
    float dist_izq = ultrasonido_izq.distancia_ultrasonico();
    float dist_der = ultrasonido_der.distancia_ultrasonico();

    if (dist_izq < dist_der) {
        desp_der(200);
    }
    else if (dist_der < dist_izq) {
        desp_izq(200);
    }
    else {
    if (direccion == "izquierda") {
        desp_izq(200);
    }
else if direccion == "derecha" {
    desp_der(200);
    }

    }

}

//Seccion 2
bool linea_blanca_izq = infrarrojo_izq.hay_linea();
bool linea_blanca_der = infrarrojo_der.hay_linea();
    if (linea_blanca_izq) {
        eleccion_desplazamiento("derecha"); 
    }
    else if (linea_blanca_der) {
        eleccion_desplazamiento("izquierda");
    }
    else {
        avanzar();
    }