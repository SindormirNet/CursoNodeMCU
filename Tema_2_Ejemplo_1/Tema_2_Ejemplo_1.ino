void setup() {
    pinMode(D7, OUTPUT);    // Indicamos que nuestro pin D7 es una salida
}

void loop() {
  digitalWrite(D7, HIGH);     //Encendemos el led 
  delay(1000);        //Esperamos 1000 ms
  digitalWrite(D7, LOW);    //Apagamos el led 
  delay(1000);        //Esperamos 1000 ms
}
