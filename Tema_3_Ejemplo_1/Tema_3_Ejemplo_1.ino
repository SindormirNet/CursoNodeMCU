#include <ESP8266WiFi.h>      
char ssid[] = "sindormir.net";    //Nombre de la red Wifi
char pass[] = "espaciomiscela";   //Contraseña de la red Wifi
void setup() {
   Serial.begin(9600);
  /*Se realiza la conexión a la red indicada con la contraseña facilitada */
   WiFi.begin(ssid,pass);
  /*Este bucle se ejecuta hasta que se completa la conexión */
  while(WiFi.status() != WL_CONNECTED ){
    Serial.print(".");
    delay(250); 
  }
  Serial.print("Conectado a la red:   ");
  Serial.println(WiFi.SSID() );
  Serial.print("Con la IP:   ");
  Serial.println(WiFi.localIP() );  
}
void loop() {
  //En esta ocasión no pondremos nada en el loop
}
