#include <SoftwareSerial.h>

const int BT_RX = 0; //ou 10
const int BT_TX = 1; //ou 11
SoftwareSerial Bluetooth(BT_RX, BT_TX);

//Esquerdo
const int  int1 = 2;
const int  int2 = 3;
//Direito
const int  int3 = 4;
const int  int4 = 5;

void setup() {
  pinMode(int1, OUTPUT);
  pinMode(int2, OUTPUT);
  pinMode(int3, OUTPUT);
  pinMode(int4, OUTPUT);
  pararCarrinho();
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() {
  if (Bluetooth.available()){
    char comando = Bluetooth.read();
    processarComando(comando);
  }
}

void processarComando(char cmd){
  switch(cmd){
    case 'F': moverParaFrente();
      break;
    case 'B': moverParaTras();
      break;
    case 'L': moverParaEsquerda();
      break;
    case 'R': moverParaDireita();
      break;
    case 'S': pararCarrinho();
      break;
    default: pararCarrinho();
      break;
  }
}

void moverParaFrente(){
    digitalWrite(int1, HIGH); //Esquerdo
    digitalWrite(int2, LOW);

    digitalWrite(int3, HIGH); //Direito
    digitalWrite(int4, LOW);
}
void moverParaTras(){
    digitalWrite(int1, LOW);
    digitalWrite(int2, HIGH);
    
    digitalWrite(int3, LOW);
    digitalWrite(int4, HIGH);
}
void moverParaEsquerda(){
    digitalWrite(int1, LOW);
    digitalWrite(int2, HIGH);
    
    digitalWrite(int3, HIGH);
    digitalWrite(int4, LOW);
}
void moverParaDireita(){
    digitalWrite(int1, HIGH);
    digitalWrite(int2, LOW);
    
    digitalWrite(int3, LOW);
    digitalWrite(int4, HIGH);
}
void pararCarrinho(){
    digitalWrite(int1, LOW);
    digitalWrite(int2, LOW);
    
    digitalWrite(int3, LOW);
    digitalWrite(int4, LOW);
}
