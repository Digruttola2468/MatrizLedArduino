#include<Wire.h>
#include<RTClib.h>

/*  Conection RTC3231
SDA --> 20 SDA 
SCL --> 21 SCL 

    Conection Display 7seg
2,3,4,5 => PIN Transistores
6,7,8,9,10,11,12 => PIN Display 7seg
a,b,c,d,e,f ,g  

    Transistores
DIS_MIL 5
DIS_CEN 3
DIS_DEC 2
DIS_UNI 4
*/

// Pines para activar cada display 7seg
#define DIS_MIL 2
#define DIS_CEN 3
#define DIS_DEC 4
#define DIS_UNI 5

const int pins[7] = {6,7,8,9,10,11,12};
//                   a,b,c,d,e ,f ,g 

//0b0gfedcba
const byte numbersDisplayAnode[10] = {
  0b00111111, //0 
  0b00000110, //1
  0b01011011, //2
  0b01001111, //3
  0b01100110, //4
  0b01101101, //5
  0b01111101, //6
  0b00000111, //7
  0b11111111, //8
  0b11101111  //9
};

//Modulo 3231
RTC_DS3231 rtc;

int horaAlta = 0;
int horaBaja = 0;
int minutoAlto = 0;
int minutoBajo = 0;

void setup() {
  Serial.begin(9600);

  // Modulo RTC3231
  if( !rtc.begin() ) {
    Serial.println("Modulo RTC no encontrado");
    while(1);
  }
  rtc.adjust(DateTime(__DATE__,__TIME__));

  //Display 7seg
  for(int i=0; i<7 ; i++){
    pinMode(pins[i], OUTPUT);
  }
  
  //Transistores para multiplexado
  pinMode(DIS_MIL,OUTPUT);
  pinMode(DIS_CEN,OUTPUT);
  pinMode(DIS_DEC,OUTPUT);
  pinMode(DIS_UNI,OUTPUT);
}

void loop() {
  DateTime fecha = rtc.now();

  int horas  = fecha.hour();                  //20
  int minutos = fecha.minute();               //47

  mostrarHoraDisplay7seg(horas,minutos);
}

void mostrarHoraDisplay7seg(int hora,int minutos){
  
  horaAlta = hora / 10;                      //20 / 10 = 2
  horaBaja = hora - (horaAlta * 10);         //20 - ( 2 * 10 ) = 0
  
  minutoAlto = minutos / 10;                  //47 / 10 = 4.7
  minutoBajo = minutos - (minutoAlto * 10) ; //47 - (4 * 10) = 7

  Serial.print(horaAlta);
  Serial.print(horaBaja);
  
  Serial.print(":");

  Serial.print(minutoAlto);
  Serial.println(minutoBajo);
  
  int tiempo = 2;
  
  //Mostrar Hora
  digitalWrite(DIS_UNI, HIGH);
  delay(tiempo);
  lightSegments(minutoBajo);
  digitalWrite(DIS_UNI, LOW);
  delay(tiempo);

  digitalWrite(DIS_DEC, HIGH);
  delay(tiempo);
  lightSegments(minutoAlto);
  digitalWrite(DIS_DEC, LOW);
  delay(tiempo);

  digitalWrite(DIS_CEN, HIGH);
  delay(tiempo);
  lightSegments(horaBaja);
  digitalWrite(DIS_CEN, LOW);
  delay(tiempo);

  digitalWrite(DIS_MIL, HIGH);
  delay(tiempo);
  lightSegments(horaAlta);
  digitalWrite(DIS_MIL,LOW);
  delay(tiempo);
}

void lightSegments(int number) {
  byte numberBit = numbersDisplayAnode[number];

  //Recorremos dentro de los 7 pines
  for(int i=0 ; i<7 ; i++){
    int bit = bitRead(numberBit, i); //Obtenemos ese bite a int
    digitalWrite(pins[i], bit);      //Enciamos
  }  
}
