/*
 * Mini Práctica 04: Entradas analógicas
 * José María Martínez Leal
 */

// Definición de pines
const int leds[5] = {14, 27, 26, 25, 33}; // LED 1 al 5
const int PinLDR = 34;                    // Fotorresistencia (LDR)

void setup() {
  Serial.begin(115200); 
  
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  
  pinMode(PinLDR, INPUT); 
}

int media(int data_number, int pin) {
  long value = 0; 
  for (int i = 0; i < data_number; i++) {
    value += analogRead(pin);
  }
  value /= data_number; 
  return (int)value;
}

void loop() {
  int nivelLuz = media(100, PinLDR);
  
  // Imprime el valor real del pin 34
  Serial.print("Nivel de luz: ");
  Serial.println(nivelLuz);

  // Apaga todos los LEDs por defecto en cada ciclo
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);
  }
  
  if (nivelLuz < 500) { 
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
    digitalWrite(leds[4], HIGH);
  } else if (nivelLuz < 1200) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
    digitalWrite(leds[3], HIGH);
  } else if (nivelLuz < 1900) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
    digitalWrite(leds[2], HIGH);
  } else if (nivelLuz < 2600) {
    digitalWrite(leds[0], HIGH);
    digitalWrite(leds[1], HIGH);
  } else if (nivelLuz < 3300) {
    digitalWrite(leds[0], HIGH);
  }
  
  delay(50); 
}