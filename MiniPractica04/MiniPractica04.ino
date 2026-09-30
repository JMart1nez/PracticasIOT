/*
 * Mini Práctica 04: Entradas analógicas
 * José María Martínez Leal
 */

//Definición de pines
const int leds[5] = {14, 27, 26, 25, 33}; // Leds
const int PinLDR = 34;                    // LDR

void setup() {
  Serial.begin(115200); 
  
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  
  pinMode(PinLDR, INPUT); 
}

//Para evitar el ruido, la función toma un bloque de lecturas, las suma en "long" y saca un promedio
int media(int data_number, int pin) {
  long value = 0; 
  for (int i = 0; i < data_number; i++) {
    value += analogRead(pin);
  }
  value /= data_number; 
  return (int)value;
}

void loop() {
  //Saca la media de 100 lecturas 
  int nivelLuz = media(100, PinLDR);
  
  //Imprime el valor en el LDR
  Serial.print("Nivel de luz: ");
  Serial.println(nivelLuz);

  //Apaga todos los LEDs por defecto en cada ciclo
  for (int i = 0; i < 5; i++) {
    digitalWrite(leds[i], LOW);
  }
  
  //Si hay ausencia de luz, todos los leds prenden y se apagan conforme aumenta la luz en un rango de 
  //0 a 4095
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