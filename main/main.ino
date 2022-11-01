//----------------Librerias--------------------
//MaxMatriz
#include <MaxMatrix.h>

//Sensor Temperatura y Humedad
#include <DHT.h>
#include <DHT_U.h>

//RTC3231
#include<Wire.h>
#include<RTClib.h>

//Caracteres para displayar la matriz de led
PROGMEM unsigned char const CH[] = {
3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // space
1, 8, B01011111, B00000000, B00000000, B00000000, B00000000, // !
3, 8, B00000011, B00000000, B00000011, B00000000, B00000000, // "
5, 8, B00010100, B00111110, B00010100, B00111110, B00010100, // #
4, 8, B00100100, B01101010, B00101011, B00010010, B00000000, // $
5, 8, B01100011, B00010011, B00001000, B01100100, B01100011, // %
5, 8, B00110110, B01001001, B01010110, B00100000, B01010000, // &
1, 8, B00000011, B00000000, B00000000, B00000000, B00000000, // '
3, 8, B00011100, B00100010, B01000001, B00000000, B00000000, // (
3, 8, B01000001, B00100010, B00011100, B00000000, B00000000, // )
5, 8, B00101000, B00011000, B00001110, B00011000, B00101000, // *
5, 8, B00001000, B00001000, B00111110, B00001000, B00001000, // +
2, 8, B10110000, B01110000, B00000000, B00000000, B00000000, // ,
4, 8, B00001000, B00001000, B00001000, B00001000, B00000000, // -
2, 8, B01100000, B01100000, B00000000, B00000000, B00000000, // .
4, 8, B01100000, B00011000, B00000110, B00000001, B00000000, // /
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // 0
3, 8, B01000010, B01111111, B01000000, B00000000, B00000000, // 1
4, 8, B01100010, B01010001, B01001001, B01000110, B00000000, // 2
4, 8, B00100010, B01000001, B01001001, B00110110, B00000000, // 3
4, 8, B00011000, B00010100, B00010010, B01111111, B00000000, // 4
4, 8, B00100111, B01000101, B01000101, B00111001, B00000000, // 5
4, 8, B00111110, B01001001, B01001001, B00110000, B00000000, // 6
4, 8, B01100001, B00010001, B00001001, B00000111, B00000000, // 7
4, 8, B00110110, B01001001, B01001001, B00110110, B00000000, // 8
4, 8, B00000110, B01001001, B01001001, B00111110, B00000000, // 9
2, 8, B01010000, B00000000, B00000000, B00000000, B00000000, // :
2, 8, B10000000, B01010000, B00000000, B00000000, B00000000, // ;
3, 8, B00010000, B00101000, B01000100, B00000000, B00000000, // <
3, 8, B00010100, B00010100, B00010100, B00000000, B00000000, // =
3, 8, B01000100, B00101000, B00010000, B00000000, B00000000, // >
4, 8, B00000010, B01011001, B00001001, B00000110, B00000000, // ?
5, 8, B00111110, B01001001, B01010101, B01011101, B00001110, // @
4, 8, B01111110, B00010001, B00010001, B01111110, B00000000, // A
4, 8, B01111111, B01001001, B01001001, B00110110, B00000000, // B
4, 8, B00111110, B01000001, B01000001, B00100010, B00000000, // C
4, 8, B01111111, B01000001, B01000001, B00111110, B00000000, // D
4, 8, B01111111, B01001001, B01001001, B01000001, B00000000, // E
4, 8, B01111111, B00001001, B00001001, B00000001, B00000000, // F
4, 8, B00111110, B01000001, B01001001, B01111010, B00000000, // G
4, 8, B01111111, B00001000, B00001000, B01111111, B00000000, // H
3, 8, B01000001, B01111111, B01000001, B00000000, B00000000, // I
4, 8, B00110000, B01000000, B01000001, B00111111, B00000000, // J
4, 8, B01111111, B00001000, B00010100, B01100011, B00000000, // K
4, 8, B01111111, B01000000, B01000000, B01000000, B00000000, // L
5, 8, B01111111, B00000010, B00001100, B00000010, B01111111, // M
5, 8, B01111111, B00000100, B00001000, B00010000, B01111111, // N
4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // O
4, 8, B01111111, B00001001, B00001001, B00000110, B00000000, // P
4, 8, B00111110, B01000001, B01000001, B10111110, B00000000, // Q
4, 8, B01111111, B00001001, B00001001, B01110110, B00000000, // R
4, 8, B01000110, B01001001, B01001001, B00110010, B00000000, // S
5, 8, B00000001, B00000001, B01111111, B00000001, B00000001, // T
4, 8, B00111111, B01000000, B01000000, B00111111, B00000000, // U
5, 8, B00001111, B00110000, B01000000, B00110000, B00001111, // V
5, 8, B00111111, B01000000, B00111000, B01000000, B00111111, // W
5, 8, B01100011, B00010100, B00001000, B00010100, B01100011, // X
5, 8, B00000111, B00001000, B01110000, B00001000, B00000111, // Y
4, 8, B01100001, B01010001, B01001001, B01000111, B00000000, // Z
2, 8, B01111111, B01000001, B00000000, B00000000, B00000000, // [
4, 8, B00000001, B00000110, B00011000, B01100000, B00000000, // \ backslash
2, 8, B01000001, B01111111, B00000000, B00000000, B00000000, // ]
3, 8, B00000010, B00000001, B00000010, B00000000, B00000000, // hat
4, 8, B01000000, B01000000, B01000000, B01000000, B00000000, // _
2, 8, B00000001, B00000010, B00000000, B00000000, B00000000, // `
4, 8, B00100000, B01010100, B01010100, B01111000, B00000000, // a
4, 8, B01111111, B01000100, B01000100, B00111000, B00000000, // b
4, 8, B00111000, B01000100, B01000100, B00101000, B00000000, // c
4, 8, B00111000, B01000100, B01000100, B01111111, B00000000, // d
4, 8, B00111000, B01010100, B01010100, B00011000, B00000000, // e
3, 8, B00000100, B01111110, B00000101, B00000000, B00000000, // f
4, 8, B10011000, B10100100, B10100100, B01111000, B00000000, // g
4, 8, B01111111, B00000100, B00000100, B01111000, B00000000, // h
3, 8, B01000100, B01111101, B01000000, B00000000, B00000000, // i
4, 8, B01000000, B10000000, B10000100, B01111101, B00000000, // j
4, 8, B01111111, B00010000, B00101000, B01000100, B00000000, // k
3, 8, B01000001, B01111111, B01000000, B00000000, B00000000, // l
5, 8, B01111100, B00000100, B01111100, B00000100, B01111000, // m
4, 8, B01111100, B00000100, B00000100, B01111000, B00000000, // n
4, 8, B00111000, B01000100, B01000100, B00111000, B00000000, // o
4, 8, B11111100, B00100100, B00100100, B00011000, B00000000, // p
4, 8, B00011000, B00100100, B00100100, B11111100, B00000000, // q
4, 8, B01111100, B00001000, B00000100, B00000100, B00000000, // r
4, 8, B01001000, B01010100, B01010100, B00100100, B00000000, // s
3, 8, B00000100, B00111111, B01000100, B00000000, B00000000, // t
4, 8, B00111100, B01000000, B01000000, B01111100, B00000000, // u
5, 8, B00011100, B00100000, B01000000, B00100000, B00011100, // v
5, 8, B00111100, B01000000, B00111100, B01000000, B00111100, // w
5, 8, B01000100, B00101000, B00010000, B00101000, B01000100, // x
4, 8, B10011100, B10100000, B10100000, B01111100, B00000000, // y
3, 8, B01100100, B01010100, B01001100, B00000000, B00000000, // z
3, 8, B00001000, B00110110, B01000001, B00000000, B00000000, // {
1, 8, B01111111, B00000000, B00000000, B00000000, B00000000, // |
3, 8, B01000001, B00110110, B00001000, B00000000, B00000000, // }
4, 8, B00001000, B00000100, B00001000, B00000100, B00000000, // ~
};

/*-----------------------Conexion de modulos-------------------------- 
Conexiones del Arduino al Modulo MAX7219 Matriz de Leds:
ARDUINIO    MAX7219
 35         CLK
 34          CS
 33          DIN
 GND         GND
 5V          VCC
 
Conexion  de la cascada de MAX7219(1) al MAX7219(2)
MAX7219(1)   MAX7219(2)  
  CLK          CLK
  CS           CS
  DOUT         DIN
  GND          GND
  VCC          VCC

Conexion con DHT11
   Vista de frente Izquierda a derecha
   1 -> VCC
   2 -> DATA -> PIN Digital
   3 -> NC (No se conecta)
   4 -> GND

Conection RTC3231
    SDA --> 20 SDA 
    SCL --> 21 SCL 

Conexion Display 7 segmentos
  Display Mil     -> PIN Digital
  Display Centena -> PIN Digital
  Display Decena  -> PIN Digital
  Display Unidad  -> PIN Digital

DIS_MIL 5
DIS_CEN 3
DIS_DEC 2
DIS_UNI 4

Conexion Pines 7 segmentos -> PINES DIGITALES
  6,7,8,9,10,11,12
  a,b,c,d, e, f, g
*/


//-----------------------------PIN------------------------------------

//Pines Display 7 segmentos
const int pins[7] = {6,7,8,9,10,11,12};
//                   a,b,c,d,e ,f ,g 

//Pines Matriz de Leds
#define DATA  51    // DIN pin del modulo MAX7219
#define LOAD  52    // CS pin del modulo MAX7219
#define CLOCK 53   // CLK pin del modulo MAX7219

//Pin DHT11 Sensor Temperatura y Humedad
#define DHTPIN 41  // PIN DHT11


//Mostrar numeros en el Display 7seg
const byte numbersDisplayAnode[10] = {
//0b0gfedcba
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

//-----------------------------Modulos------------------------------------
//Modulo 3231
RTC_DS3231 rtc;

//Modulo DHT11 sensor Temperatura y Humedad
DHT dht(DHTPIN, DHT11);                   // PINMODEL,DHTMODEL 

//Modulo Matriz de Leds
MaxMatrix m(DATA, LOAD, CLOCK, maxInUse); // Define el modulo



//-----------------------------Variables------------------------------------

//Variables para el reloj
int horaAlta = 0;
int horaBaja = 0;
int minutoAlto = 0;
int minutoBajo = 0;

//Variable MaxMatrix
int maxInUse = 2;    // Cambie este valor dependiendo del numero de matrices que use
byte buffer[2];
char mensaje1[] =  ""; // Escriba el mensaje a desplegar 

//Variable DHT
float temp = 25;
float humedad = 5;


void setup(){
  Serial.begin(9600);       // Inicializa el puerto serial
 
  m.init();                 // Inicializa el modulo Matriz de led
  m.setIntensity(5);        // Intencidad de los puntos de la matriz, entre 1-5
  
  pinMode(DHTPIN,OUTPUT);   // Definimos como salida el pin DHT

  //Verificamos si se conecto con el Modulo RTC3231
  if( !rtc.begin() ) {
    Serial.println("Modulo RTC no encontrado");
    while(1); //Bucle infinito
  }
  
  rtc.adjust(DateTime(__DATE__,__TIME__));

  //Definimos como salida a los pines Display 7seg
  for(int i=0; i<7 ; i++){
    pinMode(pins[i], OUTPUT);
  }
  
  //Transistores para multiplexado, definimos como salida
  pinMode(DIS_MIL,OUTPUT);
  pinMode(DIS_CEN,OUTPUT);
  pinMode(DIS_DEC,OUTPUT);
  pinMode(DIS_UNI,OUTPUT);
}

void loop(){
  byte c;
  
  // Lee el mensaje que llega por el puerto serial
  while (Serial.available() > 0){
    byte c = Serial.read();         //Obtiene de cada byte
    Serial.println(c,DEC);
    printCharWithShift(c, 100);
  }

  //Obtenemos los valores del sensor de temperatura 
  temp    = dht.readTemperature(); //Lee Temperatura DHT11
  humedad = dht.readHumidity();    //Lee Humedad DHT11

  //Creamos una cadena de caracteres para la frase de temperatura y humedad
  String stringMensaje;
  stringMensaje += "Temperatura: ";
  stringMensaje += temp;
  stringMensaje += "  Humedad: ";
  stringMensaje += humedad;

  //Obtenemos la cantidad total de los caracteres del string
  int mensajeLength = stringMensaje.length() + 1;

  //Pasamos de String a char[]
  char charMensaje[mensajeLength];
  stringMensaje.toCharArray(charMensaje,50);
  
  //Mostrar en la Matriz de Led
  printStringWithShift(charMensaje, 100);       // El ultimo termino se usa para la velocidad del mensaje  

  //Obtenemos la fecha y hora
  DateTime fecha = rtc.now();

  //Obtenemos los valores del modulo RTC3231
  int horas  = fecha.hour();                  
  int minutos = fecha.minute();               

  //Mostrar hora minutos en los display 7 segmentos
  mostrarHoraDisplay7seg(horas,minutos);
}

//---------------------Funciones-----------------------------------------------------------------
void printCharWithShift(char c, int shift_speed){    // Imprime caracteres
  //32 --> ALT+32 --> space
  if (c < 32) 
    return;
  
  c -= 32; 
  memcpy_P(buffer, CH + 7*c, 7);
  m.writeSprite(maxInUse*8, 0, buffer);
  m.setColumn(maxInUse*8 + buffer[0], 0);
  
  for (int i=0; i<buffer[0]+1; i++) {
    delay(shift_speed);
    m.shiftLeft(false, false);
  }
}

void printStringWithShift(char* s, int shift_speed){        // Imprime cadena de caracteres
  while (*s != 0){
    printCharWithShift(*s, shift_speed);
    s++;
  }
}

void printString(char* s)                            // Imprime cadena
{
  int col = 0;
  while (*s != 0){
    if (*s < 32) 
      continue;
    
    char c = *s - 32;
    memcpy_P(buffer, CH + 7*c, 7);
    m.writeSprite(col, 0, buffer);
    m.setColumn(col + buffer[0], 0);
    col += buffer[0] + 1;
    s++;
  }
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
