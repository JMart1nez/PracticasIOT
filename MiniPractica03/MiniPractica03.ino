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
const int btnSecuencia = 4;              //Botón SW1
const int btnReset = 15;                  //Botón SW2

int contador = 0;                         //Cuenta las pulsaciones
int estadoAnteriorBtnSecuencia = LOW;     //Memoria del estado del botón

// Variables para evitar dobles pulsaciones
unsigned long tiempoAnterior = 0;
const int umbralTiempo = 50;              //50 milisegundos de umbral

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  //Configurar botones como entrada con resistencia pulldown interna
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
  int estadoActualBtnSecuencia = digitalRead(btnSecuencia);
  int estadoBtnReset = digitalRead(btnReset);

  //Botón SW2
  //Al presionar el otro botón, todos los LEDs se apagarán y el ciclo se reinicia
  if (estadoBtnReset == HIGH) {
    apagarTodos();
    contador = 0;
  }

  //Botón SW1
  //Solo responde al momento en que el botón se presiona
  //Ignoramos si se mantiene presionado evaluando que el estado anterior sea LOW.
  if (estadoActualBtnSecuencia == HIGH && estadoAnteriorBtnSecuencia == LOW) {
    
    if (millis() > tiempoAnterior + umbralTiempo) {
      
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

  //Actualizamos la memoria del botón para el siguiente ciclo
  estadoAnteriorBtnSecuencia = estadoActualBtnSecuencia;
}