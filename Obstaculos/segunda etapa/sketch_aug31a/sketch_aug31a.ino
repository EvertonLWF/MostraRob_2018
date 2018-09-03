#include<Servo.h>
#include<Ultrasonic.h>

#define ServoH 8
#define ServoV 10
Ultrasonic HC_SR04(A0,A1);
Ultrasonic Right(A2,A3);
Ultrasonic Left(A5,A4);
int Red = 12;
int Gren = 13;
int Blue = 2;
int MotorDireita_1 = 5;
int MotorDireita_2 = 6;
int MotorEsquerda_1 = 3;
int MotorEsquerda_2 = 11;
int Status_E;
int Status_M;
int Status_D;
int x = 65;
Servo S_H;
Servo S_V;
int PosH = 87;
int PosV = 100;
int Dist_F;
int Dist_L;
int Dist_R;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Red,OUTPUT);
  pinMode(Gren,OUTPUT);
  pinMode(Blue,OUTPUT);
  pinMode(MotorDireita_1,OUTPUT);
  pinMode(MotorDireita_2,OUTPUT);
  pinMode(MotorEsquerda_1,OUTPUT);
  pinMode(MotorEsquerda_2,OUTPUT);
  S_H.attach(ServoH);
  S_H.write(PosH);
  S_V.attach(ServoV);
  S_V.write(PosV);
  Dist_F = HC_SR04.Ranging(CM);
  Dist_L = Left.Ranging(CM);
  Dist_R = Right.Ranging(CM);
  digitalWrite(Red,LOW);
  digitalWrite(Blue,LOW);
  digitalWrite(Gren,LOW);
  

}

void loop() {
  // put your main code here, to run repeatedly:
 // Dist_L = Left.Ranging(CM);
  // Serial.println(Dist_L);
 // Go();
 /**Direita_45();
 Pare();
 delay(2000);
 Esquerda_45();
 Pare();
 delay(2000);
 **/ 


}

int Frente(int x){
  digitalWrite(Red,LOW);
  digitalWrite(Blue,LOW);
  digitalWrite(Gren,HIGH);
  analogWrite(MotorDireita_1,x+20);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  analogWrite(MotorEsquerda_1,x);
  return 87;
}
int Esquerda(int x){
  digitalWrite(Red,LOW);
  digitalWrite(Blue,LOW);
  digitalWrite(Gren,HIGH);
  analogWrite(MotorDireita_1,(x+20)*1.2);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  analogWrite(MotorEsquerda_1,x);
  return 100;
}
int Direita(int x){
  digitalWrite(Red,LOW);
  digitalWrite(Blue,LOW);
  digitalWrite(Gren,HIGH);
  analogWrite(MotorDireita_1,x);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  analogWrite(MotorEsquerda_1,x*1.2);
  return 80;
}
int Re(){
    analogWrite(MotorDireita_2,95);
    digitalWrite(MotorDireita_1,LOW);
    analogWrite(MotorEsquerda_2,75);
    digitalWrite(MotorEsquerda_1,LOW);
    return 87;
}
void Pare(){
  digitalWrite(MotorDireita_1,LOW);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_1,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
}
void Esquerda_45(){
    analogWrite(MotorDireita_2,80);
    digitalWrite(MotorDireita_1,LOW);
    analogWrite(MotorEsquerda_1,80);
    digitalWrite(MotorEsquerda_2,LOW);
    delay(430);
}
void Direita_45(){
    analogWrite(MotorDireita_1,80);
    digitalWrite(MotorDireita_2,LOW);
    analogWrite(MotorEsquerda_2,80);
    digitalWrite(MotorEsquerda_1,LOW);
    delay(430);
}
void Go(){
 x=65;
  Dist_F = HC_SR04.Ranging(CM);
  delay(30);
  Dist_L = Left.Ranging(CM);
  Dist_R = Right.Ranging(CM);
  S_H.write(PosH);
  Serial.println(Dist_L);
  
  if(Dist_F > 7){
    if(Dist_R >10){
      if(Dist_L >10){
        Frente(x);
      }else{
        Direita(x);
      }}else{
        Esquerda(x);
          }
  }else{
    Pare();
    delay(500);
    if(Dist_F <= 10){
      if(Dist_L > Dist_R){
        Direita_45();
      }else{
        if(Dist_L < Dist_R){
          Esquerda_45();
      }
      }
    }
    Frente(x);
    delay(500);
}
}
void Objeto(){
    digitalWrite(Red,HIGH);
    digitalWrite(Blue,LOW);
    digitalWrite(Gren,LOW);
    Pare();
    delay(400);
    Dist_L = Left.Ranging(CM);
    delay(50);
    Dist_R = Right.Ranging(CM);
    delay(50);
    
    if(Dist_R < 20 && Dist_L < 20){
      Re();//impor condição de parada
      delay(1500);
    }else{
       if(Dist_R < Dist_L){
         digitalWrite(Red,LOW);
         digitalWrite(Gren,LOW);
         digitalWrite(Blue,HIGH);
         Direita_45();
         digitalWrite(Blue,LOW);
       }else{
          if(Dist_R > Dist_L){
            digitalWrite(Red,LOW);
            digitalWrite(Gren,LOW);
            digitalWrite(Blue,HIGH);
            Esquerda_45();
            digitalWrite(Blue,LOW);
          }
      }
    }
  Pare();
  delay(500);
  Frente(80);
  delay(600);
}

  
  

