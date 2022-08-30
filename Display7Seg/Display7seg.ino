
const int pins[7] = {33,34,35,36,37,38,39};
//                   a , b, c, d, e, f, g 


const byte numbersDisplayAnode[10] = {
  0b00000000, //0 
  0b00000000, //1
  0b00000000, //2
  0b00000000, //3
  0b00000000, //4
  0b00000000, //5
  0b00000000, //6
  0b00000000, //7
  0b00000000, //8
  0b00000000 //9
};

void setup(){
  for(int i=0; i<7 ; i++){
    pinMode(pins[i], OUTPUT);
  }

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
