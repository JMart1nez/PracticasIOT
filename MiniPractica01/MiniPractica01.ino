/*
Mini practica 01
Periodo total (T): 2 milisegundos (0.002 segundos)
Frecuencia (f): Usando la fórmula del inverso del periodo, tenemos f = 1/0.002 = 500 Hz

Nota: en delay(1) se siguen viendo puntos al mover la placa de un lado a otro, con delay(10)
ya no se nota el parpadeo con la placa estatica.
*/

const int led = 14;
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);  
  delay(1);                 
  digitalWrite(led, LOW);   
  delay(1);                
}
