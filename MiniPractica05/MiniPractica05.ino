/*
 * Mini Práctica 05: Salidas analógicas
 * José María Martínez Leal
 */

const int pinPWM = 26; // LED 3 - Salida Digital PWM
const int pinDAC = 25; // LED 4 - Salida Analógica Real (DAC 1)

float angulo = 0.0;           
const float incremento = 0.05;

void setup() {
  Serial.begin(115200);
  pinMode(pinPWM, OUTPUT);
}

void loop() {
  float ondaSeno = sin(angulo); // Valor entre -1.0 y 1.0
  
  // 1. Transformación para PWM (Rango completo: 0 a 255)
  // Amplitud de 127.5 y desplazamiento de 127.5
  float valorPWM = (ondaSeno * 127.5) + 127.5; 
  
  // 2. Transformación para DAC (Rango recortado al "encendido" del LED: 140 a 255)
  // 140 equivale a ~1.8V (donde el LED apenas empieza a brillar).
  // Amplitud = (255 - 140) / 2 = 57.5. Desplazamiento = 140 + 57.5 = 197.5
  float valorDAC = (ondaSeno * 57.5) + 197.5;

  // Escribimos las señales
  analogWrite(pinPWM, (int)valorPWM); 
  dacWrite(pinDAC, (int)valorDAC);    

  // Imprimimos en el Serial Plotter para evidenciar la distinción
  Serial.print("Señal_DAC(Recortada):");
  Serial.print(valorDAC); 
  Serial.print(",");
  Serial.print("Señal_PWM(Completa):");
  Serial.println(valorPWM);

  angulo += incremento;
  
  if (angulo >= 2 * PI) {
    angulo = 0.0;
  }

  delay(30); 
}