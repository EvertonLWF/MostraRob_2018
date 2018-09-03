/**
 * @Autor Everton Feijo
 * @brief Sequidor de linha com uma breve parada entre demarcação
 * @Data 08/28/2018
 **/
 
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
int Vaga = 2;



void setup() {
  // put your setup code here, to run once:
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

  

}


int Linha(int x){
  int y;
  if(Status_E == HIGH && Status_M == HIGH && Status_D == HIGH){
     Pare();
     return 0;
  }
  if(Status_E == HIGH && Status_M == HIGH && Status_D == LOW){
    Esquerda(x);
    return 0;
  }
  if(Status_E == HIGH && Status_M == LOW && Status_D == HIGH){
   //NULL
    return 0;
  }
  if(Status_E == HIGH && Status_M == LOW && Status_D == LOW){
    Esquerda(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == HIGH && Status_D == HIGH){
    Direita(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == HIGH && Status_D == LOW){
   Frente(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == LOW && Status_D == HIGH){
    Direita(x);
    return 0;
  }
  if(Status_E == LOW && Status_M == LOW && Status_D == LOW){
    Vaga = Parking(Vaga);
    return 0;
  }
}
void Frente(int x){
  analogWrite(MotorDireita_1,x);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  analogWrite(MotorEsquerda_1,(80*x)/100);
  return 87;
}
void Esquerda(int x){
  analogWrite(MotorDireita_1,x*1.7);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  analogWrite(MotorEsquerda_1,(x*0.9)+20);
  return 95;
}
void Direita(int x){
  analogWrite(MotorDireita_1,x*0.9);
  digitalWrite(MotorDireita_2,LOW);
  analogWrite(MotorEsquerda_1,(x*1.7)+20);
  digitalWrite(MotorEsquerda_2,LOW);
  return 79;
}
void Re(){
    analogWrite(MotorDireita_2,95);
    digitalWrite(MotorDireita_1,LOW);
    analogWrite(MotorEsquerda_2,75);
    digitalWrite(MotorEsquerda_1,LOW);
    return 87;
 }
void EsquerdaRapido(int x){
  analogWrite(MotorDireita_1,x*1.5);
  digitalWrite(MotorDireita_2,LOW);
  digitalWrite(MotorEsquerda_2,LOW);
  digitalWrite(MotorEsquerda_1,LOW);
  return 120;
}
void DireitaRapido(int x){
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
int Parking(int z){
  if(z == 2){
    do{
      Status_E= digitalRead(leitor_E);
      Frente(60);
    }while(Status_E == LOW && Status_M == LOW && Status_D == LOW);
    z--;
  }else{
    if( z==1){
      Re();
      delay(350);
      Pare();
      delay(3000); // tempo a ser definido !!!!
      z--;
    }else{
      Frente(60);
    }
  }
}

