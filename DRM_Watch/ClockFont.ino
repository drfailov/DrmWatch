#define BLOCK_WIDTH  4  // how many blocks contains one symbol
#define BLOCK_HEIGHT 5  // how many blocks contains one symbol

bool font [][20]{
  {1,1,1,1,           //0
   1,0,0,1,
   1,0,0,1,
   1,0,0,1,
   1,1,1,1},
   
  {0,1,1,0,           //1
   0,0,1,0,
   0,0,1,0,
   0,0,1,0,
   0,1,1,1},
   
  {1,1,1,1,           //2
   0,0,0,1,
   1,1,1,1,
   1,0,0,0,
   1,1,1,1},
   
  {1,1,1,1,           //3
   0,0,0,1,
   0,1,1,1,
   0,0,0,1,
   1,1,1,1},
   
  {1,0,0,1,           //4
   1,0,0,1,
   1,1,1,1,
   0,0,0,1,
   0,0,0,1},
   
  {1,1,1,1,           //5
   1,0,0,0,
   1,1,1,1,
   0,0,0,1,
   1,1,1,1},
   
  {1,1,1,1,           //6
   1,0,0,0,
   1,1,1,1,
   1,0,0,1,
   1,1,1,1},
   
  {1,1,1,1,           //7
   0,0,0,1,
   0,0,1,0,
   0,0,1,0,
   0,0,1,0},
   
  {1,1,1,1,           //8
   1,0,0,1,
   1,1,1,1,
   1,0,0,1,
   1,1,1,1},
   
  {1,1,1,1,           //9
   1,0,0,1,
   1,1,1,1,
   0,0,0,1,
   1,1,1,1},
};

void drawMessage(String text){
  clearDisplay(0);
  
  int strLen = text.length();
  int center = LCD_WIDTH/2;
  int strWidth = strLen*6;
  int strX = center-(strWidth/2);
  int strY = 20;
  
  char buf[strLen+1];
  text.toCharArray(buf, strLen+1);
  setStr(buf, strX, strY, 1);
  updateDisplay();
  delay(1000);
}

void drawText(int h, int m, int s, String text){
  clearDisplay(0);
  int y = 10;
  int m1 = m/10;
  int m2 = m - m1*10;
  int h1 = h/10;
  int h2 = h - h1*10;
  int s1 = s/10;
  int s2 = s - s1*10;
  int strLen = text.length();
  int center = LCD_WIDTH/2;
  int strWidth = strLen*6;
  int strX = center-(strWidth/2);
  int strHeight = 8;
  int strY = LCD_HEIGHT-strHeight;
  
  drawSymbol ( h1,   0,  y,  3);
  drawSymbol ( h2,  14,  y,  3);
  drawDivider(      28,  y,  3);
  drawSymbol ( m1,  32,  y,  3);
  drawSymbol ( m2,  46,  y,  3);
  drawDivider(      60,  y,  2);
  drawSymbol ( s1,  64,  y,  2);
  drawSymbol ( s2,  74,  y,  2);

  char buf[strLen+1];
  text.toCharArray(buf, strLen+1);
  setStr(buf, strX, strY, 1);
  updateDisplay();
}

void drawSymbol(int symbol, int offsetX, int offsetY, int blockSize){
  for(int bx=0;bx<BLOCK_WIDTH; bx++){
    for(int by=0;by<BLOCK_HEIGHT;by++){
      int bitIndex = bx + by * BLOCK_WIDTH;
      bool fill = font[symbol][bitIndex];
      if(fill){
        int x = blockSize*bx + offsetX;
        int y = blockSize*by + offsetY;
        setRect(x, y, x+blockSize-1, y+blockSize-2, true, true);
      }
    }
  }
}

void drawDivider(int offsetX, int offsetY, int blockSize){
  bool map[5] = {0,1,0,1,0};
  for(int by=0;by<BLOCK_HEIGHT;by++){
    bool fill = map[by];
    if(fill){
      int x = offsetX;
      int y = blockSize*by + offsetY;
      setRect(x, y, x+blockSize-1, y+blockSize-2, true, true);
    }
  }
}

