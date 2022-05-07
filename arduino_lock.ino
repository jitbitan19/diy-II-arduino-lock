const int button[] = {2,3,4,5};
const int led[] = {6,7,8,9};

const int green = 10;
const int red = 11;

int code[] = {4,2,1,3};
int input[4];
int is_entered = 0;
int accept = 150;

void setup(){
  Serial.begin(9600);
  
  for (int i = 0; i < 4; i++){
    pinMode(button[i], INPUT);
    pinMode(led[i], OUTPUT);
  }

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  led_check();
}

void loop(){
  if (digitalRead(button[0]) == HIGH){
    digitalWrite(led[0], HIGH);
    is_entered = append_input(1);
    Serial.println("button 1 is pressed");
    delay(accept);
    digitalWrite(led[0], LOW);
  }
  
  if (digitalRead(button[1]) == HIGH){
    digitalWrite(led[1], HIGH);
    is_entered = append_input(2);
    Serial.println("button 2 is pressed");
    delay(accept);
    digitalWrite(led[1], LOW);
  }
  
  if (digitalRead(button[2]) == HIGH){
    digitalWrite(led[2], HIGH);
    is_entered = append_input(3);
    Serial.println("button 3 is pressed");
    delay(accept);
    digitalWrite(led[2], LOW);
  }
  
  if (digitalRead(button[3]) == HIGH){
    digitalWrite(led[3], HIGH);
    is_entered = append_input(4);
    Serial.println("button 4 is pressed");
    delay(accept);
    digitalWrite(led[3], LOW);
  }
  
  if (is_entered == 4){
    validate();
    Serial.println("Circuit reset!");
    is_entered = 0;
  }
}

void led_check(){
  for (int i = 0; i < 4; i++){
    digitalWrite(led[i], HIGH);
    delay(250);
  }
  for (int i=0; i < 4; i++){
    digitalWrite(led[i], LOW);
  }
}

int append_input(int data){
  input[is_entered] = data;
  return is_entered + 1;
}

void validate(){
  Serial.println("Checking...");
  int ok = 1;
  
  for (int i = 0; i < 4; i++){
    if (input[i] != code[i]){
      ok = 0;
      break;
    }
  }
  
  if (ok == 1){
    blink(green);
    Serial.println("Matched!");
  }
  else{
    blink(red);
    Serial.println("Not Matched!");
  }
}

void blink(int button){
  for (int i = 0; i < 5; i++){
      digitalWrite(button, HIGH);
      delay(100);
      digitalWrite(button, LOW);
      delay(100);
    }
}