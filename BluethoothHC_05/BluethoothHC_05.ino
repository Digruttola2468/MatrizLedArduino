
/*Modulo HC-05 Bluethooth

  Conneccion:
  VCC - VCC   GND - GND
  TXD - 10
  RXD - 11

  User: IVAN-05
  Password: 1234

  App celular: bluetooth serial controller
*/

//Importamos la libreria
#include <SoftwareSerial.h>

SoftwareSerial miBluethooth(10, 11); //TX 10,DX 11

void setup() {
  Serial.begin(9600);
  miBluethooth.begin(38400);
}

void loop() {

  if (miBluethooth.available()) {
    char Dato = miBluethooth.read();
    Serial.println(Dato);
  }
  if (Serial.available())
  miBluethooth.write(10);
}
