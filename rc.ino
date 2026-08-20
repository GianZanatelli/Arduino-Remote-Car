#include <SoftwareSerial.h>

// Bluetooth
const int BT_TX = 10; 
const int BT_RX = 11; 
SoftwareSerial Bluetooth(BT_RX, BT_TX);

// Motores                                                               LEGENDA
const int int1 = 2;//                                 MOTOR A - Esquerdo         Motor B - Direito
const int int2 = 3;//
const int int3 = 4;//                       FRENTE ->            int 1                      int 3  
const int int4 = 5;//                       TRAS   ->            int 2                      int 4

// Luzes
const int Farol = 6;
const int LuzRe = 7;
const int SetaEsquerda = 8;
const int SetaDireita = 9;
const int PiscaAlerta = 12;

// Sons
const int Buzina = 13;

void setup() {
  pinMode(int1, OUTPUT);
  pinMode(int2, OUTPUT);
  pinMode(int3, OUTPUT);
  pinMode(int4, OUTPUT);
  PararCarrinho();
  pinMode(Farol, OUTPUT);
  pinMode(LuzRe, OUTPUT);
  pinMode(SetaEsquerda, OUTPUT);
  pinMode(SetaDireita, OUTPUT);
  pinMode(PiscaAlerta,OUTPUT);
  pinMode(Buzina, OUTPUT);
  Serial.begin(9600);
  Bluetooth.begin(9600);
}

void loop() {
  if (Bluetooth.available()){
    char comando = Bluetooth.read();
    ProcessarComando(comando);
  }
}

void ProcessarComando(char cmd){
  switch(cmd){
    case 'L': MoverParaEsquerda();
      break;
    case 'R': MoverParaDireita();
      break;
    case 'F': MoverParaFrente();
      break;
    case 'G': MoverParaFrenteEsquerda();
      break;
    case 'I': MoverParaFrenteDireita();
      break;
    case 'B': MoverParaTras();
      break;
    case 'H': MoverParaTrasEsquerda();
      break;
    case 'J': MoverParaTrasDireita();
      break;
    case 'S': PararCarrinho();
      break;
    case 'W': AcenderFarol();
      break;
    case 'w': ApagarFarol();
      break;
    case '0': ASetaEsquerda();
      break;
    case 'q': ASetaDireita();
      break;
    case 'X': AcenderPiscaAlerta();
      break;
    case 'x': ApagarPiscaAlerta();
      break;
    case 'V': Buzinar();
      break;
    case 'v': PararBuzina();
      break;

    default: PararCarrinho();
      break;
  }
}

void MoverParaEsquerda(){

  //Motor A - Esquerdo
    digitalWrite(int1, LOW); //Frente
    digitalWrite(int2, LOW);  //Tras

  //Motor B - Direito
    digitalWrite(int3, HIGH); //Frente
    digitalWrite(int4, LOW);  //Tras

    digitalWrite(SetaEsquerda, HIGH);
    digitalWrite(LuzRe, LOW);
}
void MoverParaDireita(){

  //Motor A - Esquerdo
    digitalWrite(int1, HIGH); //Frente
    digitalWrite(int2, LOW);  //Tras

  //Motor B - Direito
    digitalWrite(int3, LOW); //Frente
    digitalWrite(int4, LOW);  //Tras

    digitalWrite(SetaDireita, HIGH);
    digitalWrite(LuzRe, LOW);
}
void MoverParaFrente(){

  //Motor A - Esquerdo
    digitalWrite(int1, HIGH); //Frente
    digitalWrite(int2, LOW);  //Tras

  //Motor B - Direito
    digitalWrite(int3, HIGH); //Frente
    digitalWrite(int4, LOW);  //Tras

    digitalWrite(SetaEsquerda, LOW);
    digitalWrite(SetaDireita, LOW);
    digitalWrite(LuzRe, LOW);
}
void MoverParaFrenteEsquerda(){

  //Motor A - Esquerdo
    digitalWrite(int1, LOW); //Frente
    digitalWrite(int2, LOW);  //Tras

  //Motor B - Direito
    digitalWrite(int3, HIGH); //Frente
    digitalWrite(int4, LOW);  //Tras

    digitalWrite(SetaEsquerda, HIGH);
    digitalWrite(LuzRe, LOW);
}
void MoverParaFrenteDireita(){

  //Motor A - Esquerdo
    digitalWrite(int1, HIGH); //Frente
    digitalWrite(int2, LOW);  //Tras

  //Motor B - Direito
    digitalWrite(int3, LOW); //Frente
    digitalWrite(int4, LOW);  //Tras

    digitalWrite(SetaDireita, HIGH);
    digitalWrite(LuzRe, LOW);
}
void MoverParaTras(){

  //Motor A - Esquerdo
    digitalWrite(int1, LOW); //Frente
    digitalWrite(int2, HIGH);  //Tras

  //Motor B - Direito
    digitalWrite(int3, LOW); //Frente
    digitalWrite(int4, HIGH);  //Tras

    digitalWrite(SetaEsquerda, LOW);
    digitalWrite(SetaDireita, LOW);
    digitalWrite(LuzRe, HIGH);
}
void MoverParaTrasEsquerda(){

  //Motor A - Esquerdo
    digitalWrite(int1, LOW); //Frente
    digitalWrite(int2, LOW);  //Tras

  //Motor B - Direito
    digitalWrite(int3, LOW); //Frente
    digitalWrite(int4, HIGH);  //Tras

    digitalWrite(LuzRe, HIGH);
}
void MoverParaTrasDireita(){

  //Motor A - Esquerdo
    digitalWrite(int1, LOW); //Frente
    digitalWrite(int2, HIGH);  //Tras

  //Motor B - Direito
    digitalWrite(int3, LOW); //Frente
    digitalWrite(int4, LOW);  //Tras

    digitalWrite(LuzRe, HIGH);
}
void PararCarrinho(){

  //Motor A - Esquerdo
    digitalWrite(int1, LOW); //Frente
    digitalWrite(int2, LOW);  //Tras

  //Motor B - Direito
    digitalWrite(int3, LOW); //Frente
    digitalWrite(int4, LOW);  //Tras

    digitalWrite(SetaEsquerda, LOW);
    digitalWrite(SetaDireita, LOW); 
    digitalWrite(LuzRe, LOW);
}
void AcenderFarol(){
    digitalWrite(Farol, HIGH);
}
void ApagarFarol(){
    digitalWrite(Farol, LOW);
}
void ASetaEsquerda(){
    digitalWrite(SetaEsquerda, HIGH);
}
void ASetaDireita(){
    digitalWrite(SetaDireita, HIGH);
}
void AcenderPiscaAlerta(){
    digitalWrite(PiscaAlerta, HIGH);
}
void ApagarPiscaAlerta(){
    digitalWrite(PiscaAlerta, LOW);
}
void Buzinar(){
    tone(Buzina, 200);
}
void PararBuzina(){
    noTone(Buzina);
}
