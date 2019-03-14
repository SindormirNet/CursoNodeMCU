#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char ssid[] = "sindormir.net";   //Nombre de la red Wifi
const char pass[] = "espaciomiscela";    //Contraseña de la red Wifi
ESP8266WebServer server(80);

void  miWeb() {

  String web = "<!DOCTYPE HTML><html><body>";
  web += "<form action = ' ' ><input type = 'text' name = 'nombreCaja' />";
  web += "<input type = 'submit' value = 'Enviar' /></form>";
  web += "Recibido: <br><br>";
  web += "Direccion: ";
  web += server.uri();
  web += "<br>Metodo: ";

  /*Comprobamos si recibimos los datos por GET o POST*/
  if (server.method() == HTTP_GET) {
    web += "GET";
  } else {
    web += "POST";
  }

  web += "<br>Argumentos: ";
  web += server.args();
  web += "<br>";

  for (int i = 0;  i < server.args();  i ++) {
    web += " " + server.argName(i) + ": " + server.arg(i) + "<br>" ;
  }

  web += "</body></html>";
  server.send(200, "html", web );
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
