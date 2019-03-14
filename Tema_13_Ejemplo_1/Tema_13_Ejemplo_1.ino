#include <ESP8266WiFi.h>
#include <ESP8266WiFiMesh.h>

#define TONO 33        //Frecuencia de un Do
#define ZUMBADOR D2
#define MI_TURNO "1755960"

String  manageRequest(String  recibido) {

  Serial.print("recibido: ");
  Serial.println(recibido);
    
  if (recibido == MI_TURNO) {
    tone(ZUMBADOR, TONO);
    delay(250); 
    noTone(ZUMBADOR); 
  } else {
    /*código que se ejecuta si no es el turno del modulo*/
  }

  //Devolvemos el String para que sea enviado
  char respuesta[60];
    sprintf(respuesta, "Mensaje%d", ESP.getChipId( ));
  return respuesta; 
}

ESP8266WiFiMesh miMalla=ESP8266WiFiMesh(ESP.getChipId(), manageRequest);
void setup() {
  Serial.begin(9600); 
  Serial.print("Mi ID");
  Serial.println(ESP.getChipId() );
  pinMode(ZUMBADOR, OUTPUT);  

  //Inicializamos la malla
  miMalla.begin( );
}

void loop() {
  //Aceptamos peticiones entrantes
  miMalla.acceptRequest( );

  //Escaneamos otros nodos y les enviamos un mensaje
  char respuesta[60];
  sprintf(respuesta, "Mensaje%d", ESP.getChipId( ));
  miMalla.attemptScan(respuesta);
  delay(1000);
}
