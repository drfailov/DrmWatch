unsigned long lastValue = 0;
unsigned int  curHour = 0;
unsigned int  curMinute = 0;
unsigned int  curSecond = 0;


void processTime(){
  drawText(curHour, curMinute, curSecond, "DRM Watch");
  wait();
  tick();
}

void tick(){
  curSecond ++;
  if(curSecond >= 60){
    curSecond = 0;
    curMinute ++;
  }
  if(curMinute >= 60){
    curMinute = 0;
    curHour ++;
  }
  if(curHour >= 24){
    curHour = 0;
  }
}

void wait(){
  //this function waiting exactly for 1 second every time it called 
  unsigned long threshold = lastValue + 1000;
  while(millis() < threshold);
  lastValue = millis();
}
int getHours(){
  return curHour;
}
void incHours(){
  curHour++;
  if(curHour >= 24)
    curHour = 0;
}
int getMinutes(){
  return curMinute;
}
void incMinutes(){
  curMinute++;
  if(curMinute >= 60)
    curMinute = 0;
}
void resetSeconds(){
  curSecond = 0;
}

