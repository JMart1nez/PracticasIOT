/*
Mini practica 01
José María Martínez Leal
*/

/*
Definimos el led
*/

const int led = 14;

void setup() {
  pinMode(led, OUTPUT);

}

/*
Prendemos y apagamos utilizando 10 milisegundos en delay
*/
void loop() {
  digitalWrite(led, HIGH);  
  delay(10);                 
  digitalWrite(led, LOW);   
  delay(10);
             
}

/*
Periodo total T = 20 milisegundos = 0.020 segundos
Frecuencia f = 1/0.020 = 50 Hz

Nota: 
A los 22 milisegundos (45.45 Hz) se nota que aun parpadea un poco pero en 20 milisegundos desaparece el parpadeo 

*/