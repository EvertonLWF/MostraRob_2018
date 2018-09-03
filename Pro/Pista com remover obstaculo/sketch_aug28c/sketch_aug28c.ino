/**
 * @Autor Everton Feijo
 * @brief Sequidor de linha retirar obstaculo na pista 
 * @Data 08/28/2018
 **/

 
#include<Servo.h>
#include<Ultrasonic.h>
#define ServoH 8
Ultrasonic HC_SR04(A0,A1);
int MotorDireita_1 = 5;
int MotorDireita_2 = 6;
int MotorEsquerda_1 = 3;
int MotorEsquerda_2 = 11;
const int leitor_D = 2;
const int leitor_E = 4;
const int leitor_M = 7;
int Status_E;
int Status_M;
int Status_D;
int x = 80;
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
  if(Dist > 50 ){
    x=80;
    Linha(x);
  }else{
    if(Dist > 15 && Dist < 50 ){
      x = 80;
      Linha(x);
    }else{
      if(Dist < 10){
        Pare();
        delay(200);
        RetirarObjeto();
      }
    }
  }
      
}

int Linha(int x){
  int y;
  if(Status_E == HIGH && Status_M == HIGH && Status_D == HIGH){
     Pare();
     return 0;
  }
  if(Status_E == HIGH && Status_M == HIGH && Status_D == LOW){
    //PosH = Esquerda(x);
    return 0;
  }
  if(Status_E == HIGH && Status_M == LOW && Status_D == HIGH){
   //NULL
    return 0;
  }
  if(Status_E == HIGH && Status_M == LOW && Status_D == LOW){
    PosH = Esquerda(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == HIGH && Status_D == HIGH){
    //PosH = Direita(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == HIGH && Status_D == LOW){
   PosH = Frente(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == LOW && Status_D == HIGH){
    PosH = Direita(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == LOW && Status_D == LOW){
    Re();
    return 0;
  }
}

int Frente(int x){
  analogWrite(MotorDireita_1,x);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  analogWrite(MotorEsquerda_1,(80*x)/100);
  return 87;
}
int Esquerda(int x){
  analogWrite(MotorDireita_1,x*1.7);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  analogWrite(MotorEsquerda_1,(x*0.9)+20);
  return 95;
}
int Direita(int x){
  analogWrite(MotorDireita_1,x*0.9);
  digitalWrite(MotorDireita_2,LOW);
  analogWrite(MotorEsquerda_1,(x*1.7)+20);
  digitalWrite(MotorEsquerda_2,LOW);
  return 79;
}
int Re(){
    analogWrite(MotorDireita_2,95);
    digitalWrite(MotorDireita_1,LOW);
    analogWrite(MotorEsquerda_2,75);
    digitalWrite(MotorEsquerda_1,LOW);
    return 87;
 }
int EsquerdaRapido(int x){
  analogWrite(MotorDireita_1,x*1.5);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  digitalWrite(MotorEsquerda_1,LOW);
  return 120;
}
int DireitaRapido(int x){
  digitalWrite(MotorDireita_1,LOW);
  digitalWrite(MotorDireita_2,LOW);
  analogWrite(MotorEsquerda_1,(x*1.5)+20);
  digitalWrite(MotorEsquerda_2,LOW);
  return 60;
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
void RetirarObjeto(){
    Esquerda_90();
    delay(250);
    Pare();
    delay(350);
    Curva_D();
    delay(1300);
    Pare();
    delay(350);
    Esquerda_90();
    delay(250);
    do{
      Status_E= digitalRead(leitor_E);
      Status_M= digitalRead(leitor_M);
      Status_D= digitalRead(leitor_D);
       PosH = Re();
    }while(Status_E == LOW && Status_E == LOW && Status_E == LOW);
     delay(400);
     do{
      Status_E= digitalRead(leitor_E);
      Status_M= digitalRead(leitor_M);
      Status_D= digitalRead(leitor_D);
      Curva_D();
    }while(Status_E == LOW && Status_E == LOW && Status_E == LOW);
     
}
void Esquerda_90(){
    analogWrite(MotorDireita_2,100);
    digitalWrite(MotorDireita_1,LOW);
    analogWrite(MotorEsquerda_1,120);
    digitalWrite(MotorEsquerda_2,LOW);
}
void Direita_90(){
    analogWrite(MotorDireita_1,100);
    digitalWrite(MotorDireita_2,LOW);
    analogWrite(MotorEsquerda_2,120);
    digitalWrite(MotorEsquerda_1,LOW);
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
    Esquerda_90();
    delay(250);
    Pare();
    delay(350);
    Curva_D();
    delay(1500);
    Pare();
    delay(350);
    do{
      Status_E= digitalRead(leitor_E);
      PosH = Frente(80);
    }while(Status_E == LOW);
}
void DesvioD(){
    Direita_90();
    delay(330);
    Pare();
    delay(350);
    Curva_E();
    delay(2500);
    Pare();
    delay(350);
    Direita_90();
    delay(330);
    Pare();
    delay(350);
}

