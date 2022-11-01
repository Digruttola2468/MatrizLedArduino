// 2,3,4,5 PIN Transistores
// 6,7,8,9,10,11,12 PIN Display 7seg
// a,b,c,d,e,f,g

const int pins[7] = {6,7,8,9,10,11,12};
//                   a , b, c, d, e, f, g 

#define DIS_MIL 4   //PIN 2
#define DIS_CEN 3   //PIN 3
#define DIS_DEC 2   //PIN 4
#define DIS_UNI 5   //PIN 5

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

int unidad = 0;
int decena = 0;
int centena = 0;
int mil = 0;

void setup(){
  for(int i=0; i<7 ; i++){
    pinMode(pins[i], OUTPUT);
  }
  
  //Transistores
  pinMode(DIS_MIL,OUTPUT);
  pinMode(DIS_CEN,OUTPUT);
  pinMode(DIS_DEC,OUTPUT);
  pinMode(DIS_UNI,OUTPUT);
}

void loop(){
  
  if(unidad == 10 ){
    unidad = 0;
    decena++;
  }
  if(decena == 10) {
    decena = 0;
    unidad = 0;
    centena++;
  }
  if(centena == 10){
    unidad = 0;
    decena = 0;
    centena = 0;
    mil++;
  }
  if(mil == 10){
    unidad = 0;
    decena = 0;
    centena = 0;
    mil = 0;
  }

  int tiempo = 100;
  
  //Mostrar Hora
  digitalWrite(DIS_UNI, HIGH);
  delay(tiempo);
  lightSegments(unidad);
  digitalWrite(DIS_UNI, LOW);
  delay(tiempo);

  digitalWrite(DIS_DEC, HIGH);
  delay(tiempo);
  lightSegments(decena);
  digitalWrite(DIS_DEC, LOW);
  delay(tiempo);

  digitalWrite(DIS_CEN, HIGH);
  delay(tiempo);
  lightSegments(centena);
  digitalWrite(DIS_CEN, LOW);
  delay(tiempo);

  digitalWrite(DIS_MIL, HIGH);
  delay(tiempo);
  lightSegments(mil);
  digitalWrite(DIS_MIL,LOW);
  delay(tiempo);
  
  unidad++;
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
