#include <Arduino.h>
#include "sensores/sensores.h"
#include "motores/motores.h"

//Sensores(creo)
#include <WString.h>
long  dist_ultrasonico;
String leer_color;
bool linea_blanca;
byte pared_front = 10; //valor q define dist de ult_front con pared
byte pared_izq = 50; //valor q define dist de ult_izq con carrito, en caso de girar a la izq
byte  pared_der = 50;// valor que define dist de ult_der con carrito, en caso de girar a la der
bool giro_pendiente = false; //variable q define si hay giro pendiente, para q no se quede en un loop infinito
bool pelota_detectada = true; //
void loop() {

    //Seccion 1

    if (pelota_detectada != true) {
    }
    else if (pelota_detectada == true) {
    }

    if (ultrasonico_der < 45 && ultrasonico_front < 40) { 
        pelota_detectada != true;
    //despues del avanzar lo de abajo se haría si la dist del ultr_der es menor a 45,
    //indicando que es la entrada a la pelota
       detener();
       izquierda();//aqui ocupo ponerlo en 90° especif para que el intake tome la pelota
       encender_intake(); //aun no esta esta funcion pero es u ejemplo
       retroceder();
       pelota_detectada == true;
    }

    else {
       avanzar();
    }

    if (ultrasonico_front < 10 && ultrasonico_der > 50) {
    giro_pendiente = true;
    }
    

    if (giro_pendiente) {
        if (ultrasonico_der < 10) {
            giro_pendiente = false;
        }
        else {
            desp_der(200);
        }
    }


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

if (ultrasonico_izq() <10 && ultrasonico_der() <10){
    retroceder(200);
}
detener();

if (ultrasonico_izq() >10) {
    if (leer_color() !=rojo) {
        desp_izq(200);
    }
}
    detener();
}
else (ultrasonico_der() >10) {
    if (leer_color() !="rojo") {
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

    //Seccion 3

    if (sensor_rgb.leer_color()== "naranja"); {
        avanzar();
    }
    else if (sensor_rgb.leer_color()== "azul"); {
        desp_der();
    }
    else if (sensor_rgb.leer_color()== "rosa"); {
        retroceder();
    }
    

