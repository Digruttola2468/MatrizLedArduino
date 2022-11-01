// 2,3 PIN Transistores
// 5,6,7,8,9,10,11 PIN Display 7seg
// a,b,c,d,e,f,g

const int pins[7] = {6,7,8,9,10,11,12};
//                   a , b, c, d, e, f, g 

#define DIS_MIL 4   //PIN 2

//0b0gcbafed
const byte numbersDisplayAnode[10] = {
  //0b0fgedcba
  0b01011111, //0 
  0b00000110, //1
  0b00111011, //2
  0b00101111, //3
  0b01101100, //4
  0b01101101, //5
  0b01111101, //6
  0b00000111, //7
  0b01111111, //8
  0b01100111  //9
};

void setup(){
  for(int i=0; i<7 ; i++){
    pinMode(pins[i], OUTPUT);
  }

  pinMode(DIS_MIL,OUTPUT);
  
  lightSegments(0);
  delay(10000000);
}

void loop(){
  digitalWrite(DIS_MIL,HIGH);
  for(int i=0 ; i<10 ; i++){
    lightSegments(i);
    delay(1000);
  }
}

/**
Esta funcion permite encender el segmento con el numero
pasando como argumento

int number del 0 al 9
*/
void lightSegments(int number) {
  byte numberBit = numbersDisplayAnode[number];

  //Recorremos dentro de los 7 pines
  for(int i=0 ; i<7 ; i++){
    int bit = bitRead(numberBit, i); //Obtenemos ese bite a int
    digitalWrite(pins[i], bit);      //Enciamos
  }  
}
