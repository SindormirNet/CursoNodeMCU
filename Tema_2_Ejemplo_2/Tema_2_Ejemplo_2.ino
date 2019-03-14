#define LED D7        //Creamos una constante LED de valor D7 
int tiempo = 1000;        //Creamos una variable de valor 1000
void setup() {
   pinMode(LED, OUTPUT);     // Indicamos que nuestro pin D7 es una salida
}

void loop() {
  digitalWrite(LED, HIGH);    //Encendemos el led 
  delay(tiempo);      //Esperamos 1000 ms
  digitalWrite(LED, LOW);     //Apagamos el led 
  delay(tiempo);      //Esperamos 1000 ms
}
