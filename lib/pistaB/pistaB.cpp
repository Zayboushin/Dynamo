#include <Arduino.h>
#include "sensores.h"
#include "control.h"
#include "motores.h"


//Sensores(creo)
long  dist_ultrasonico;
String leer_color;
bool linea_blanca;
byte pared_front = 10; //valor q define dist de ult_front con pared
byte pared_izq = 50; //valor q define dist de ult_izq con carrito, en caso de girar a la izq
byte  pared_der = 50;// valor que define dist de ult_der con carrito, en caso de girar a la der
static bool giro_pendiente = false; //variable q define si hay giro pendiente, para q no se quede en un loop infinito
bool pelota_detectada = false; //
bool giro_der = false; // para q sepa a que lado girar en grados
bool giro_izq =false;
bool pelota_tomada = false;
String direcciones[] = {"izquierda", "derecha"};

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
     }
    else {
        avanzar(vel, vel);
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

    //la condicion no toma en cuenta que la logica de 90 grados necesita seguir girando.
    // ¿qu pasa si la variable de pelota detectada cambia mientras esta girando?
    if (!pelota_detectada) {
        if (dist_der < 45 && dist_frente < 40) { //encuentra el recuadro de la pelota

            pelota_detectada = true;
            giro_pendiente = true;
            logica_90grados(giro_pendiente);
            izquierda(200);
    

        }
        else {
            navegacion();
        }
    }

    if (pelota_detectada && !pelota_tomada) {
        
        if(!retroalimentacion_limit_switch()) {
            encender_intake(200);//falta agregar
            retroceder(vel);
        }
        else {
            detener();
            apagar_intake(0);//falta
            pelota_tomada = true;
        }
        }
    if (pelota_tomada && dist_frente > 10) {
        avanzar(200,200);
        }
    else if (pelota_tomada && dist_frente < 10) {
        salida1(); //algo tiene mal lo tengo que corregir
    }
    else {
        navegacion();
    }
    }


void seccion_2()
{
    
eleccion_desplazamiento(direcciones[0]);


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
void eleccion_desplazamiento(String direccion) {
    if (dist_izq < dist_der) {
        desp_der(200);
    }
    else if (dist_der < dist_izq) {
        desp_izq(200);
    }
    else if (direccion == direcciones[0]) {
        desp_izq(200);
    }
    else if (direccion == direcciones[1]) {
    desp_der(200);
    }   


bool linea_blanca_izq = infrarrojo_izq.linea_blanca();
bool linea_blanca_der = infrarrojo_der.linea_blanca();
    
    if (linea_blanca_izq) { 
        eleccion_desplazamiento(direcciones[1]);  //revisar errores
    }
     
    else if (linea_blanca_der) {
        eleccion_desplazamiento(direcciones[0]);
    }
    else {
        avanzar(vel, vel);
    }
    
}