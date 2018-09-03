/*PROJETO SIRENE COM BUZZER by ON ELECTRONIC*/

float seno;
int frequencia;
 
void setup() {
 pinMode(6,OUTPUT); //define o pino 9 como saída
}
 
void loop() {
 for(int x=0;x<180;x++){
  
  //converte graus (o X da equação) para radiando e depois obtém o valor do seno
  seno=(sin(x*3.1416/180));
  
  //gera uma frequência a partir do valor do seno
  frequencia = 2000 + (int(seno*1000));
  tone(6,frequencia);
  delay(2);
 }
}
