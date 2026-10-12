#define S0 45
#define S1 44
#define S2 46
#define S3 49
#define salidaTCS 8

void setup() {
    pinMode (S0, OUTPUT);
    pinMode (S1, OUTPUT);
    pinMode (S2, OUTPUT);
    pinMode (S3, OUTPUT);
    pinMode (salidaTCS, INPUT);

    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);

    Serial.begin (9600);
}

void loop() {
    //rojo
    digitalWrite (S2, LOW);
    digitalWrite (S3, LOW);
    int rojo = pulseIn(salidaTCS, LOW);

    //verde
    digitalWrite (S2, HIGH);
    digitalWrite (S3, HIGH);
    int verde = pulseIn(salidaTCS, LOW);

    //azul
    digitalWrite (S2, LOW);
    digitalWrite (S3, HIGH);
    int azul = pulseIn(salidaTCS, LOW);

    if (rojo == 0 || verde == 0 || azul == 0) return;

    float r =  1000.0 / rojo;
    float g = 1000.0 / verde;
    float b = 1000.0 / azul;

    float mx = max(r, max(g, b));
    float mn = min(r, min(g, b));
    float diferencia = mx - mn;

  // Calcular el tono (0 a 360)
  float tono = 0;
  if (diferencia > 0) { //
    if (mx == r)      
        tono = 60 * fmod((g - b) / diferencia, 6);
    else if (mx == g)       
        tono = 60 * ((b - r) / diferencia + 2);
    else if 
        tono = 60 * ((r - g) / diferencia + 4);
    if (tono < 0)
        tono += 360;
  }

  Serial.print("R: ");  Serial.print(rojo);
  Serial.print("  G: "); Serial.print(verde);
  Serial.print("  B: "); Serial.print(azul);
  Serial.print("  Tono: "); Serial.println(tono);


    }

    //void navegacion

    //karla
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

void limit_switch() {

    bool limit_switch = false;

}

void salida1() { //condiciones para salir de secc 1
    if (ultrasonico_front > 10) {
        avanzar();
    }
    else {
        
    }
    
    if (pelota_tomada && ultrasonico_front >20 && ultrasonico_izq > 40 && ultrasonico_der < 20) {
        giro_pendiente = true;
        giro_izq = true;
        logica_90grados(giro_pendiente);

    }
}