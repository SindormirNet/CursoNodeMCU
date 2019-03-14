#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>  
#include <WiFiClient.h>   
const char  ssid[] = "miESP8266";   //Nombre de la red Wifi
const char pass[] = "mimodulo";   //Contraseña de la red Wifi

ESP8266WebServer server(80);

void miWeb() {
  server.send(200, "text/html", "<h1>Conectado a la Red</h1>");
}

void setup() {
  Serial.begin(9600);
  Serial.println("Configurando punto de acceso...");

  WiFi.softAP(ssid,pass);
  IPAddress myIP = WiFi.softAPIP( );
  
  Serial.print("Direccion IP:   ");
  Serial.println(myIP);
  server.on ("/", miWeb);
  server.begin ( );
  Serial.print("Servidor HTTP iniciado correctamente");
}
void loop() {
  server.handleClient ( );
}
