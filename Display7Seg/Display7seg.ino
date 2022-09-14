// 2,3 PIN Transistores
// 5,6,7,8,9,10,11 PIN Display 7seg
// a,b,c,d,e,f,g

const int pins[7] = {5,6,7,8,9,10,11};
//                   a , b, c, d, e, f, g 


//0b0gcbafed
const byte numbersDisplayAnode[10] = {
  0b00111111, //0 
  0b00110000, //1
  0b01011011, //2
  0b01111001, //3
  0b01110100, //4
  0b01101101, //5
  0b01101111, //6
  0b00111000, //7
  0b01111111, //8
  0b01111100  //9
};

void setup(){
  
  for(int i=0; i<7 ; i++){
    pinMode(pins[i], OUTPUT);
  }
  
  
  //Transistores
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  
  
  lightSegments(0);
}

void loop(){
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
