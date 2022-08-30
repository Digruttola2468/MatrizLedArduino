#include<DHT.h>

#define PINDHT 2
#define PINMODE DHT11

DHT dht(PINDHT,PINMODE);

void setup(){
  Serial.begin(9600);
  dht.begin();
}
void loop(){
  int temp = dht.readTemperature();
  int hume = dht.readHumidity();
  
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print("°C");

  Serial.print("  ");

  Serial.print("Humedad:");
  Serial.print(hume);
  Serial.println("%");
  
  delay(1000);
}
