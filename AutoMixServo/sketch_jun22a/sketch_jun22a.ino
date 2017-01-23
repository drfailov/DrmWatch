#include <Servo.h>

Servo s;
void setup() {
  // put your setup code here, to run once:
  s.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<180; i++){
    s.write(i);
    delay(10);
  }
  for(int i=180; i>=0; i--){
    s.write(i);
    delay(10);
  }

}
