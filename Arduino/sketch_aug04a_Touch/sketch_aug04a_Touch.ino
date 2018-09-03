
int button = 2;
int var;
int state;


void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_BUILTIN, LOW);
  state = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Estado da porta = ");
  Serial.println(state);
  var = digitalRead(button);
  if (var == 1 && state == 0){
    state=1;
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
  }else{
    if (var == 1 && state == 1){
      state=2;
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
    }
  }
  
}
