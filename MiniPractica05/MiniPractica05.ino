/*
 * Mini Práctica 05: Salidas analógicas
 * José María Martínez Leal
 */

const int pinPWM = 26; //Salida Digital PWM
const int pinDAC = 25; //Salida Analógica DAC
#define pinADCPWM 13
#define pinADCDAC 12

float angulo = 0.0;           
const float incremento = 0.05;

#define frequencyPWM     1000  //Frecuencia en Hz
#define resolutionPWM    8     //Bits de resolución, hasta 8

void setup() {
  Serial.begin(115200);
  pinMode(pinPWM, INPUT);
  pinMode(pinDAC, INPUT);
  pinMode(pinADCPWM, OUTPUT);
  pinMode(pinADCDAC, OUTPUT);

  //Configuración del PWM
  ledcAttach(pinPWM, frequencyPWM, resolutionPWM);
}

void loop() {

  for (int i = 0; i < 360; i++) {
    float senDAC = sin(i * (M_PI / 180)); //Seno para DAC
    float senPWM = sin(i * (M_PI / 180)); //Seno para PWM

    // Transformación para PWM (Rango 0 a 255)
    // Amplitud de 127.5 y desplazamiento de 127.5
    float valorPWM = (senPWM * 127.5) + 127.5;

    //Transformación para DAC (Rango recortado al encendido del LED: 140 a 255)
    // 140 equivale a 1.8V (El led apenas empieza a brillar).
    // Amplitud = (255 - 140) / 2 = 57.5. Desplazamiento = 140 + 57.5 = 197.5
    float valorDAC = (senDAC * 57.5) + 197.5;

    //Salidas
    ledcWrite(pinPWM, (int)valorPWM); 
    dacWrite(pinDAC, (int)valorDAC); 

    //Imprimir en serial plotter
    Serial.print("Señal_DAC:");
    Serial.print(analogRead(pinADCDAC)); 
    Serial.print(",");
    Serial.print("Señal_PWM:");
    Serial.println(analogRead(pinADCPWM));

    delayMicroseconds(1000);
  }
}