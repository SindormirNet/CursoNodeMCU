#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>      
const char ssid[] = "sindormir.net";   //Nombre de la red Wifi
const char pass[] = "espaciomiscela";    //Contraseña de la red Wifi
ESP8266WebServer server(80);

void miWeb() {
  server.send(200, "text/plain", "HOLA MUNDO");
}
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
  server.on("/", miWeb);  
  server.begin( );
  Serial.println("Servidor HTTP activo");
}
void loop() {
  server.handleClient( );
}
