const int led_R =3;
const int led_G =5;
const int led_B =6;
int i;

void setup() {
  // put your setup code here, to run once:
  analogWrite(led_G, 0);
  analogWrite(led_R, 0);
  analogWrite(led_B, 0);
  

}

void loop() {
  for(i=0;i<255;i++){
    delay(15);
    analogWrite(led_G, i);
  }
  analogWrite(led_G, LOW);
  for(i=0;i<255;i++){
    delay(15);
    analogWrite(led_B, i);
  }
  analogWrite(led_B, LOW);
  for(i=0;i<255;i++){
    delay(15);
    analogWrite(led_R, i);
  }
  analogWrite(led_R, LOW);
  for(i=0;i<255;i++){
    delay(15);
    analogWrite(led_R, i);
    analogWrite(led_G, i);
  }
  analogWrite(led_R, LOW);
  analogWrite(led_G, LOW);
  for(i=0;i<255;i++){
    delay(15);
    analogWrite(led_R, i);
    analogWrite(led_B, i);
  }
  analogWrite(led_R, LOW);
  analogWrite(led_B, LOW);
  for(i=0;i<255;i++){
    delay(15);
    analogWrite(led_B, i);
    analogWrite(led_G, i);
  }
  analogWrite(led_B, LOW);
  analogWrite(led_G, LOW);
  for(i=0;i<255;i++){
    delay(15);
    analogWrite(led_B, i);
    analogWrite(led_G, i);
    analogWrite(led_R, i);
  }
  analogWrite(led_R, LOW);
  analogWrite(led_G, LOW);
  analogWrite(led_B, LOW);
  
   
}
