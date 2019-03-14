#include <ESP8266WiFi.h>  
#include <WiFiClient.h> 
/*Definimos el nombre de la red que creará el ESP y su contraseña*/ 
const char  ssid[] = "miESP8266"; //Nombre de la red Wifi
const char pass[] = "mimodulo";   //Contraseña de la red Wifi
 void setup() {
  Serial.begin(9600);
  Serial.println("Configurando punto de acceso...");

  WiFi.softAP(ssid,pass);
  IPAddress myIP = WiFi.softAPIP( );
  
  Serial.print("Direccion IP:   ");
  Serial.println(myIP);
}
void loop() {
  //En esta ocasión no pondremos nada en el loop
}
