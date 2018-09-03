#include<Servo.h>
#include<Ultrasonic.h>
#define ServoH 8
Ultrasonic HC_SR04(A0,A1);
int MotorDireita_1 = 5;
int MotorDireita_2 = 6;
int MotorEsquerda_1 = 3;
int MotorEsquerda_2 = 11;
const int leitor_D = 4;
const int leitor_E = 7;
const int leitor_M = 2;

int Status_E;
int Status_M;
int Status_D;
int x = 55;
Servo S_H;
int PosH = 87;
int Dist;


void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(MotorDireita_1,OUTPUT);
  pinMode(MotorDireita_2,OUTPUT);
  pinMode(MotorEsquerda_1,OUTPUT);
  pinMode(MotorEsquerda_2,OUTPUT);
  pinMode(leitor_D,INPUT);
  pinMode(leitor_M,INPUT);
  pinMode(leitor_E,INPUT);
  S_H.attach(ServoH);
  S_H.write(PosH);
  Dist = HC_SR04.Ranging(CM);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  Dist = HC_SR04.Ranging(CM);
  Status_E= digitalRead(leitor_E);
  Status_D= digitalRead(leitor_D);
  Status_M= digitalRead(leitor_M);
  S_H.write(PosH);
  if(Dist > 70 ){
    x=90;
    Linha(x);
    
  }else{
    if(Dist > 15 && Dist < 50 ){
      x = 60;
      Linha(x);
    }else{
      if(Dist < 10){
        Pare();
        ObjetoDetec();
      }
    }
  }
  
  //Frente(x); 
}

int Linha(int x){
  int y;
  if(Status_E == HIGH && Status_M == HIGH && Status_D == HIGH){
     Re();
    // Vaga = CaminhoFaltando(Vaga);
     return 0;
  }
  if(Status_E == HIGH && Status_M == HIGH && Status_D == LOW){
    PosH = Esquerda(x);
    return 0;
  }
  if(Status_E == HIGH && Status_M == LOW && Status_D == HIGH){
   //NULL
    return 0;
  }
  if(Status_E == HIGH && Status_M == LOW && Status_D == LOW){
   PosH =  EsquerdaRapido(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == HIGH && Status_D == HIGH){
    PosH = Direita(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == HIGH && Status_D == LOW){
   PosH = Frente(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == LOW && Status_D == HIGH){
   PosH =  DireitaRapido(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == LOW && Status_D == LOW){
//    Vaga = Parking(Vaga);
    return 0;
  }
}

int Frente(int x){
  analogWrite(MotorDireita_1,x+15);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  analogWrite(MotorEsquerda_1,x);
  return 87;
}
int Esquerda(int x){
  analogWrite(MotorDireita_1,x+20);
  digitalWrite(MotorDireita_2,LOW);
  analogWrite(MotorEsquerda_1,x*0.6);//(x*1.7)+20)
  digitalWrite(MotorEsquerda_2,LOW);
  return 100;
}
int Direita(int x){
  analogWrite(MotorDireita_1,(x*0.6)+20);
  digitalWrite(MotorDireita_2,LOW);
  analogWrite(MotorEsquerda_1,x);//(x*1.7)+20)
  digitalWrite(MotorEsquerda_2,LOW);
  return 60;
}
int Re(){
    analogWrite(MotorDireita_2,95);
    digitalWrite(MotorDireita_1,LOW);
    analogWrite(MotorEsquerda_2,75);
    digitalWrite(MotorEsquerda_1,LOW);
    return 87;
 }
int EsquerdaRapido(int x){
  analogWrite(MotorDireita_1,x*1.6);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  digitalWrite(MotorEsquerda_1,LOW);
  return 120;
}
int DireitaRapido(int x){
  digitalWrite(MotorDireita_1,LOW);
  digitalWrite(MotorDireita_2,LOW);
  analogWrite(MotorEsquerda_1,(x*1.6)+20);
  digitalWrite(MotorEsquerda_2,LOW);
  return 45;
}
void Pare(){
  digitalWrite(MotorDireita_1,LOW);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_1,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
}
void ObjetoDetec(){
  
    DesvioE();
  
}
void Esquerda_45(){
    analogWrite(MotorDireita_2,60);
    digitalWrite(MotorDireita_1,LOW);
    analogWrite(MotorEsquerda_1,70);
    digitalWrite(MotorEsquerda_2,LOW);
    delay(300);
}
void Direita_45(){
    analogWrite(MotorDireita_1,60);
    digitalWrite(MotorDireita_2,LOW);
    analogWrite(MotorEsquerda_2,70);
    digitalWrite(MotorEsquerda_1,LOW);
    delay(300);
}
void Curva_E(){
    analogWrite(MotorDireita_1,80);
    digitalWrite(MotorDireita_2,LOW);
    digitalWrite(MotorEsquerda_2,LOW);
    analogWrite(MotorEsquerda_1,140);
}
void Curva_D(){
    analogWrite(MotorDireita_1,140);
    digitalWrite(MotorDireita_2,LOW);
    digitalWrite(MotorEsquerda_2,LOW);
    analogWrite(MotorEsquerda_1,70);
}

void DesvioE(){
    Esquerda_45();
    delay(250);
    Pare();
    delay(350);
    Curva_D();
    delay(1500);
    Pare();
    delay(350);
    Pare();
    do{
      Status_E= digitalRead(leitor_E);
      PosH = Frente(80);
    }while(Status_E == LOW);
}
void DesvioD(){
    Direita_45();
    delay(330);
    Pare();
    delay(350);
    Curva_E();
    delay(2500);
    Pare();
    delay(350);
    Direita_45();
    delay(330);
    Pare();
    delay(350);
}

