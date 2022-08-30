#include<Wire.h>
#include<RTClib.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);

  if( !rtc.begin() ){
    Serial.println("Modulo RTC no encontrado");
    while(1);
  }
  rtc.adjust(DateTime(__DATE__,__TIME__));
}

void loop() {
  DateTime fecha = rtc.now();

   Serial.print(fecha.day());
   Serial.print("/");
   
   Serial.print(fecha.month());
   Serial.print("/");
   
   Serial.print(fecha.year());
   Serial.print("   ");

   
   Serial.print(fecha.hour());
   Serial.print(":");
   
   Serial.print(fecha.minute());
   Serial.print(":");

   Serial.print(fecha.second());
   Serial.println();

   delay(1000);
}
