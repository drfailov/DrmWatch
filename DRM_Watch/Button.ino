int buttonModePin = 8;
int buttonSetPin = 9;

int buttonModeClicked = 0;

void initButtons(){
  pinMode(buttonModePin, INPUT);
  pinMode(buttonSetPin, INPUT);
}

boolean isButtonMode(){
  boolean value = digitalRead(buttonModePin);
  Serial.print("Pin mode ");
  Serial.print(buttonModePin);
  Serial.print(" value = ");
  Serial.println(value);
  return value;
}

boolean isButtonSet(){
  boolean value = digitalRead(buttonSetPin);
  Serial.print("Pin set ");
  Serial.print(buttonSetPin);
  Serial.print(" value = ");
  Serial.println(value);
  return value;
}

void processMode(){
  
}

