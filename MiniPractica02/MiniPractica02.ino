/*
Mini practica 02
José María Martínez Leal
*/

#define led1 14
#define led2 27
#define led3 26
#define led4 25
#define led5 33

// Definimos los leds de uso en un arreglo de tamaño 5
const int leds[5] = {led1, led2, led3, led4, led5};

void setup() {
  for (int i = 0; i < 5 ; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Recorrido de ida: del LED 1 al 5
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], HIGH); // Enciende el LED actual
    delay(50);                  // Mantiene encendido por 50 ms
    digitalWrite(leds[i], LOW);  // Apaga el LED actual antes del siguiente paso
  }

  // Recorrido de vuelta: del LED 4 al 2
  for (int i = 3; i >= 1; i--) {
    digitalWrite(leds[i], HIGH);
    delay(50);
    digitalWrite(leds[i], LOW);
  }
}