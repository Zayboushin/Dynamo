#include <Arduino.h>
#include "sensores.h"
#include "control.h"
#include "motores.h"


//Sensores(creo)
#include <WString.h>
long  dist_ultrasonico;
String leer_color;
bool linea_blanca;
byte pared_front = 10; //valor q define dist de ult_front con pared
byte pared_izq = 50; //valor q define dist de ult_izq con carrito, en caso de girar a la izq
byte  pared_der = 50;// valor que define dist de ult_der con carrito, en caso de girar a la der
bool giro_pendiente = false; //variable q define si hay giro pendiente, para q no se quede en un loop infinito
bool pelota_detectada = false; //
bool giro_der = false; // para q sepa a que lado girar en grados
bool giro_izq =false;
bool pelota_tomada = false;


//
//variables de ultrasonicos

    float dist_izq = ultrasonico_izq.distancia_ultrasonico();
    float dist_der = ultrasonico_der.distancia_ultrasonico();
    float dist_frente = ultrasonico_frente.distancia_ultrasonico();
    //karla

//variables de movimiento
byte vel = 200;

void pistaB()
{
    float dist_izq = ultrasonico_izq.distancia_ultrasonico();
    float dist_der = ultrasonico_der.distancia_ultrasonico();
    float dist_frente = ultrasonico_frente.distancia_ultrasonico();

    void navegacion() {

     if (dist_frente < 10 && dist_der > 50) { //giro a la derecha por pasillo-
        giro_pendiente = true;
        giro_der = true;
        logica_90grados(giro_pendiente);
     }
    else {
        avanzar();
    }
}

void salida1() { //condiciones para salir de secc 1
    
    if (pelota_tomada && dist_frente > 20 && dist_izq > 40 && dist_der < 20) {
        giro_pendiente = true;
        giro_izq = true;
        logica_90grados(giro_pendiente);
    }
}

seccion_1()
{

        if (!pelota_detectada) {
        if (dist_der < 45 && dist_frente < 40) { //encuentra el recuadro de la pelota

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
            pelota_tomada = true;
        }
        }
    if (pelota_tomada) {
        if (giro_pendiente) {
            logica_90grados(giro_pendiente);
        }
    else if (pelota_tomada) {
        salida1();
    }
    else {
        navegacion();
    }
    }

}

seccion_2()
{
    
eleccion_desplazamiento(direccion);





}

seccion_3()
{
    
    if (sensor_rgb.leer_color()== "naranja") {
        avanzar(vel, vel);
    }
    else if (sensor_rgb.leer_color()== "azul") {
        desp_der(vel);
    }
    else if (sensor_rgb.leer_color()== "amarillo") {
        desp_izq(vel);
    }
    else if (sensor_rgb.leer_color()== "rosa") {
        retroceder(vel);
    }

}

//Funciones de movimiento internas

}

void navegacion() {

     if (dist_frente < 10 && dist_der > 50) { //giro a la derecha por pasillo-
        giro_pendiente = true;
        giro_der = true;
        logica_90grados(giro_pendiente);
     }
    else {
        avanzar();
    }
}

void salida1() { //condiciones para salir de secc 1
    
    if (pelota_tomada && dist_frente > 20 && dist_izq > 40 && dist_der < 20) {
        giro_pendiente = true;
        giro_izq = true;
        logica_90grados(giro_pendiente);
    }
}

void seccion_1()
{

        if (!pelota_detectada) {
        if (dist_der < 45 && dist_frente < 40) { //encuentra el recuadro de la pelota

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
            pelota_tomada = true;
        }
        }
    if (pelota_tomada) {
        if (giro_pendiente) {
            logica_90grados(giro_pendiente);
        }
    else if (pelota_tomada) {
        salida1();
    }
    else {
        navegacion();
    }
    }

}

void seccion_2()
{
    
eleccion_desplazamiento(direccion);





}

void seccion_3()
{
    
    if (sensor_rgb.leer_color()== "naranja") {
        avanzar(vel, vel);
    }
    else if (sensor_rgb.leer_color()== "azul") {
        desp_der(vel);
    }
    else if (sensor_rgb.leer_color()== "amarillo") {
        desp_izq(vel);
    }
    else if (sensor_rgb.leer_color()== "rosa") {
        retroceder(vel);
    }

}

//Funciones de movimiento internas
void eleccion_desplazamiento(string direccion) {
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
else if (direccion == "derecha") {
    desp_der(200);
    }

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
    
    }