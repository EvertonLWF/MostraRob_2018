//configuração seguidor de trilhas

int MotorDireita_1 = 5;
int MotorDireita_2 = 6;
int MotorEsquerda_1 = 10;
int MotorEsquerda_2 = 11;
const int leitor_D = 3;
const int leitor_E = 4;
const int leitor_M = 7;
int Status_E;
int Status_M;
int Status_D;
int Led_R = 2;
int Led_G = 8;
int Led_B = 9;
int x = 130;//speed



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(Led_R,OUTPUT);
  pinMode(Led_G,OUTPUT);
  pinMode(Led_B,OUTPUT);
  pinMode(MotorDireita_1,OUTPUT);
  pinMode(MotorDireita_2,OUTPUT);
  pinMode(MotorEsquerda_1,OUTPUT);
  pinMode(MotorEsquerda_2,OUTPUT);
  pinMode(leitor_D,INPUT);
  pinMode(leitor_M,INPUT);
  pinMode(leitor_E,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Status_E= digitalRead(leitor_E);
  Status_D= digitalRead(leitor_D);
  Status_M= digitalRead(leitor_M);

  if(Status_M == HIGH){
    if(Status_E == LOW && Status_D == HIGH){
      virarEsquerda(x);
    }else{
      if(Status_E == HIGH && Status_D == LOW){
        virarDireita(x);
      }else{
        frente(x);
      }
    }
  }else{
    if(Status_E == LOW && Status_D == HIGH){
      virarEsquerdaRapido(x);
    }else{
      if(Status_E == HIGH && Status_D == LOW){
        virarDireitaRapido(x);
      }else{
        frente(x);
      }
    }
  }
  if(Status_E == HIGH && Status_D == HIGH && Status_M == HIGH){
    Pare();
  }
  if(Status_E == LOW && Status_D == LOW && Status_M == LOW){
   Pare();
  }
}
void virarDireita(int x){
  analogWrite(MotorDireita_1,x/2);
  analogWrite(MotorDireita_2,0);
  analogWrite(MotorEsquerda_1,0);
  analogWrite(MotorEsquerda_2,x);
  digitalWrite(Led_G,HIGH);
}

void virarEsquerda(int x){
  analogWrite(MotorDireita_1,x);
  analogWrite(MotorDireita_2,0);
  analogWrite(MotorEsquerda_1,0);
  analogWrite(MotorEsquerda_2,x/2);
  digitalWrite(Led_G,HIGH);

}
void virarDireitaRapido(int x){
  analogWrite(MotorDireita_1,LOW);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_1,LOW);
  digitalWrite(MotorEsquerda_2,HIGH);
  digitalWrite(Led_G,HIGH);
}

void virarEsquerdaRapido(int x){
  digitalWrite(MotorDireita_1,HIGH);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_1,LOW);
  analogWrite(MotorEsquerda_2,LOW);
  digitalWrite(Led_G,HIGH);

}
void frente(int x){
  noTone(12);
  analogWrite(MotorDireita_1,x+20);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_1,LOW);
  analogWrite(MotorEsquerda_2,x+20);
  digitalWrite(Led_G,HIGH);
}
void Pare(){
    analogWrite(MotorDireita_1,0);
    analogWrite(MotorDireita_2,0);
    analogWrite(MotorEsquerda_1,0);
    analogWrite(MotorEsquerda_2,0);    
}

