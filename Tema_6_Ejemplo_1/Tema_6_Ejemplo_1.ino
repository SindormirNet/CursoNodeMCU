#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>      
const char ssid[] = "sindormir.net";   //Nombre de la red Wifi
const char pass[] = "espaciomiscela";    //Contraseña de la red Wifi
ESP8266WebServer server(80);

void  miWeb() {
  /*Cabeceras de la página, así el navegador lo identificará como una web */
  String web = "<!DOCTYPE HTML><html><body>";
  
    /*Comprobamos el estado del botón 1 y emitimos un mensaje */
  if (digitalRead(D2)) {
    web = web + "<h1>BOTON 1 PULSADO </h1>";
  } else {
    web = web + "<h1>BOTON 1 SIN PULSAR </h1>";
  }

  /*Comprobamos el estado del botón 2 y emitimos un mensaje */
  if (digitalRead(D3)) {
    web = web + "<h1>BOTON 2 PULSADO </h1>";
  } else {
    web = web + "<h1>BOTON 2 SIN PULSAR </h1>";
  }
  
  /*Etiquetas de cierrre de la web */
  web = web + "</body></html>";
  /*Enviamos la web al servidor activo en el puerto 80 de nuestro ESP8266*/
  server.send(200, "html", web );
  delay(100);
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
