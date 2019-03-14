#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define LED D7

const char ssid[] = "sindormir.net";   //Nombre de la red Wifi
const char pass[] = "espaciomiscela";    //Contraseña de la red Wifi
ESP8266WebServer server(80);

void  miWeb() {
  String web = "<!DOCTYPE HTML><html><body>";
  web += "<form action = ' ' ><input type = 'submit' name = 'led_btn' value = '1' />";  web += "<input type = 'submit' name = 'led_btn' value = '0' /></form>";
    for (int i = 0;  i < server.args();  i ++) {
      if (server.argName(i) == "led_btn"){
        if (server.arg(i) == "0"){
          digitalWrite(LED, LOW);
        } else {
           digitalWrite(LED, HIGH);
        }
      } else {
        Serial.println("No reconozco el argumento");
      }
    }
  web += "</body></html>";
  server.send(200,"html", web );
  delay(100); 
}

void setup() {
  Serial.begin(9600);
  /*Se realiza la conexión a la red indicada con la contraseña facilitada */
  WiFi.begin(ssid, pass);
  /*Este bucle se ejecuta hasta que se completa la conexión */
  while (WiFi.status() != WL_CONNECTED ) {
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
