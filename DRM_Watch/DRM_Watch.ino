
/* 84x48 LCD Defines: */

/* 
 * DESIGNED BY MESSER
 * PROGRAMMED BY DR. FAILOV 
 * ASSEMBLED IN UKRAINE
 */
#define LCD_WIDTH   84 // Note: x-coordinates go wide
#define LCD_HEIGHT  48 // Note: y-coordinates go high
#define MODE_CLOCK  0 
#define MODE_SET_MINUTES  1
#define MODE_SET_HOURS  2 
 
int mode = 0;



void setup()
{
  Serial.begin(9600);
  lcdBegin(); // This will setup our pins, and initialize the LCD
  setContrast(60); // Good values range from 40-60
  updateDisplay(); // with displayMap untouched, SFE logo
  delay(2000);
  clearDisplay(0);
  updateDisplay();
  delay(500);
}


void loop()
{
  if(mode == MODE_CLOCK){
    processTime();
    
    if(isButtonMode()){
      drawMessage("HOLD MORE!");
      if(isButtonMode()){
        drawMessage("MORE!!!");
          if(isButtonMode()){
            drawMessage("SET HOURS");
            mode = MODE_SET_HOURS;
          }
      }
    }
  }
  if(mode == MODE_SET_HOURS){
    if(isButtonSet()){
      incHours();
      drawText(getHours(), getMinutes(), 0, "SET HOURS");
      delay(200);
    }
    if(isButtonMode()){
        drawMessage("SET MINUTES");
        mode = MODE_SET_MINUTES;
    }
    drawText(getHours(), getMinutes(), 0, "SET HOURS");
  }
  if(mode == MODE_SET_MINUTES){
    if(isButtonSet()){
      incMinutes();
      drawText(getHours(), getMinutes(), 0, "SET MINUTES");
      delay(200);
    }
    if(isButtonMode()){
        resetSeconds();
        drawMessage("GO!");
        mode = MODE_CLOCK;
    }
    drawText(getHours(), getMinutes(), 0, "SET MINUTES");
  }
}






