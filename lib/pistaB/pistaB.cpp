#include <Arduino.h>
#include "sensores.h"
#include "motores.h"
#include "control.h"
//logica90 grad

//Sensores(creo)
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
bool salida_secc1 = false;
int seccion = 1;
bool salida_seccion1 = false;
bool salida_seccion2 = false;
bool salida_seccion3 = false;
//
//variables de ultrasonicos

    float dist_izq = 0.0f;
    float dist_der = 0.0f;
    float dist_frente = 0.0f;
    //karla

//variables de movimiento
byte vel = 200;

void navegacion();
void salida1();
void seccion_1();
void seccion_2();
void seccion_3();

//Funciones de movimiento internas
void eleccion_desplazamiento(String direccion);

void pistaB()
{
    dist_izq = ultrasonico_izq.distancia_ultrasonico();
    dist_der = ultrasonico_der.distancia_ultrasonico();
    dist_frente = ultrasonico_frente.distancia_ultrasonico();

    navegacion();

    salida1();

    seccion_1();
    seccion_2();
    seccion_3();

//Funciones de movimiento internas

}

void navegacion() {

     if (dist_frente < 10 && dist_der > 50) { //giro a la derecha por pasillo-
        giro_pendiente = true;
        giro_der = true;
        logica_90grados(giro_pendiente);
        derecha(200);
     }
    else {
        avanzar(200, 200);
    }
}
/////hacer un bool
void salida1() { //condiciones para salir de secc 1
    
    if (dist_frente > 20 && dist_izq > 40 && dist_der < 20) {
        giro_pendiente = true;
        logica_90grados(giro_pendiente);
        izquierda(200);
        salida_seccion1 = true;
    }
}

void seccion_1()
{

    if (seccion == 1) { //act sin tomar pelota
        if (!salida_seccion1) {
        salida1();
        }
        else {
            navegacion();
    }
}
    if (salida_seccion1)
    {
        seccion = 2;
    }
  
}


void seccion_2()
{
    if (seccion == 2) {
eleccion_desplazamiento("izquierda"); //
    if (salida_seccion2) {
        seccion = 3;
    }
}
}






void seccion_3()
{
    if (seccion == 3) {
    
    
    if (sensor_rgb.leer_color()== "naranja") {
        avanzar(200, 200);
    }
    else if (sensor_rgb.leer_color()== "azul") {
        desp_der(200);
    }
    else if (sensor_rgb.leer_color()== "amarillo") {
        desp_izq(200);
    }
    else if (sensor_rgb.leer_color()== "rosa") {
        retroceder(200);
    }
    }
    if (salida_seccion3) {
        //que pongoooo
    }
}

//Funciones de movimiento internas
void eleccion_desplazamiento(String direccion) {
   
    if (dist_izq < dist_der) {
        desp_der(200);
    }
    else if (dist_der < dist_izq) {
        desp_izq(200);
    }
    else if (direccion == "izquierda") {
        desp_izq(200);
    }
    
    else if (direccion == "derecha") {
    desp_der(200);
    }   

bool linea_blanca_izq = infrarrojo_izq.linea_blanca();
bool linea_blanca_der = infrarrojo_der.linea_blanca();
    
    if (linea_blanca_izq) {
        eleccion_desplazamiento("derecha"); 
    }
     
    else if (linea_blanca_der) {
        eleccion_desplazamiento("izquierda");
    }
    else {
        avanzar(200, 200);
    }
}

  