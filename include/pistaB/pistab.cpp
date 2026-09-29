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
bool pelota_detectada = false //
bool giro_der = false; // para q sepa a que lado girar en grados
bool giro_izq =false;
bool pelota_tomada = false;


void loop() {

    //Seccion 1

    if (!pelota_detectada) {
        if (ultrasonico_der < 45 && ultrasonico_front < 40) { //encuentra el recuadro de la pelota

            pelota_detectada = true;
            giro_pendiente = true;
            giro_der = true; //corregir
        }
        else {
            navegacion();
        }
    }

    if (pelota_detectada && !pelota_tomada) {
        if (giro_pendiente) {
            logica_90grados(giro_pendiente);
        }
        else if(!limit_switch) {
            encender_intake();//falta agregar
            retroceder();
        }
        else {
            detener();
            apagar_intake();//falta
            pelota_tomada = true
        }
        }
    if (pelota_tomada) {
        if (giro_pendiente) {
            logica_90grados(giro_pendiente);
        }
    else 
        salida1();
        navegacion();
    }


//Salir de seccion 1


    
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
    }
else if direccion == "derecha" {
    desp_der(200);
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

    if (sensor_rgb.leer_color()== "naranja") {
        avanzar();
    }
    else if (sensor_rgb.leer_color()== "azul") {
        desp_der();
    }
    else if (sensor_rgb.leer_color()== "amarillo") {
        desp_izq();
    }
    else if (sensor_rgb.leer_color()== "rosa") {
        retroceder();
    }
    

