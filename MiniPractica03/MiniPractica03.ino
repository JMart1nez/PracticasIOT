/*
 * Mini Práctica 03: Entradas digitales
 * José María Martínez Leal
 */

//Definimos pines

#define led1 14
#define led2 27
#define led3 26
#define led4 25
#define led5 33

const int leds[5] = {led1, led2, led3, led4, led5}; // Leds 1 al 5
const int btnSecuencia = 4;              //Botón SW2
const int btnReset = 15;                  //Botón SW1

int contador = 0;                         //Cuenta las pulsaciones
int estadoAnteriorBtnSecuencia = LOW;     //Memoria del estado del botón

// Variables para evitar dobles pulsaciones
unsigned long tiempoAnterior = 0;         //Guarda el tiempo en el que el estado cambio correctamente
const int umbralTiempo = 50;              //si otra accion ocurre en menos de 50ms se ignora

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  //Configurar botones como entrada con pulldown
  pinMode(btnSecuencia, INPUT_PULLDOWN); 
  pinMode(btnReset, INPUT_PULLDOWN);
}

//Función para apagar todos los Leds
void apagarTodos() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void loop() {
  //Se guarda el estado actual de los botones
  int estadoActualBtnSecuencia = digitalRead(btnSecuencia);
  int estadoBtnReset = digitalRead(btnReset);

  //Botón SW1
  //Al presionar SW1, todos los LEDs se apagarán y el ciclo se reinicia
  if (estadoBtnReset == HIGH) {
    apagarTodos();
    contador = 0;
  }

  //Botón SW2
  //Accion al presionar SW2
  //Si el boton esta presionado y antes estaba suelto
  if (estadoActualBtnSecuencia == HIGH && estadoAnteriorBtnSecuencia == LOW) {
    
    //Verificamos que hayan pasado mas de 50ms desde el ultimo estado registrado
    if (millis() - tiempoAnterior > umbralTiempo) {
      
      contador++; //Aumenta el registro de la pulsación
      
      //Si se superan las 5 pulsaciones, el ciclo se reinicia
      if (contador > 5) {
        apagarTodos();
        contador = 0;
      } else {
        //Los Leds se encienden uno por uno sumándose al anterior
        digitalWrite(leds[contador - 1], HIGH);
      }
      
      tiempoAnterior = millis(); //Actualizamos el reloj
    }
  }
  //En otro caso, si el boton esta suelto y hace un momento estaba presionado
  else if (estadoActualBtnSecuencia == LOW && estadoAnteriorBtnSecuencia == HIGH){

    tiempoAnterior = millis(); //Atualizamos el reloj para evitar otra pulsacion
  }

  //Actualizamos la memoria del botón
  estadoAnteriorBtnSecuencia = estadoActualBtnSecuencia;
}