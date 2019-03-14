#define LED D7  
#define POT A0  
int valorSalida;
int lecturaAnalogica;
void setup() {
   Serial.begin(9600);  
}
void loop() {
  lecturaAnalogica = analogRead(A0); 
  valorSalida = map(lecturaAnalogica, 0, 1023, 0, 255);
  analogWrite(LED, valorSalida); 
}
