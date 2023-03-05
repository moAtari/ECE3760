#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// Pin definitions for ESP32
#define TFT_CS    5
#define TFT_RST   16
#define TFT_DC    17

// Create an instance of the ST7735 library
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void DisplayInit(){
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(3);
  tft.setTextSize(1);
  
}

void command(){
  tft.setCursor(15, 0);
  tft.setTextColor(ST7735_WHITE);
  tft.println("The command goes here");
  tft.setCursor(0,18);
  tft.println("(Background will change color with diffent commands)");
}

void intensityDirection(uint8_t level){
  
  tft.setCursor(0, 40);
  tft.println("Intensity Lvl: ");
  tft.setCursor(0, 90);
  tft.println("Direction: "); 
  tft.drawRect(10,55,25,25,ST7735_BLUE); 
  tft.drawRect(35,55,25,25,ST7735_BLUE);  
  tft.drawRect(60,55,25,25,ST7735_BLUE);  
  tft.drawRect(85,55,25,25,ST7735_BLUE);
  switch(level){
    case('0'):
      tft.fillRect(12,56,21,22,ST7735_BLACK);  
      tft.fillRect(37,56,21,22,ST7735_BLACK);
      tft.fillRect(62,56,21,22,ST7735_BLACK);
      tft.fillRect(87,56,21,22,ST7735_BLACK);      
    break;
    case('1'):
      
      tft.fillRect(12,56,21,22,ST7735_CYAN);
      tft.fillRect(37,56,21,22,ST7735_BLACK);
      tft.fillRect(62,56,21,22,ST7735_BLACK);
      tft.fillRect(87,56,21,22,ST7735_BLACK);
      break;
    case('2'):
      tft.fillRect(12,56,21,22,ST7735_CYAN); 
      tft.fillRect(37,56,21,22,ST7735_CYAN);
      tft.fillRect(62,56,21,22,ST7735_BLACK);
      tft.fillRect(87,56,21,22,ST7735_BLACK);
      break;
    case('3'):
      tft.fillRect(12,56,21,22,ST7735_CYAN); 
      tft.fillRect(37,56,21,22,ST7735_CYAN);
      tft.fillRect(62,56,21,22,ST7735_CYAN);
      tft.fillRect(87,56,21,22,ST7735_BLACK);
      break;       
    case('4'):
      tft.fillRect(12,56,21,22,ST7735_CYAN); 
      tft.fillRect(37,56,21,22,ST7735_CYAN);
      tft.fillRect(62,56,21,22,ST7735_CYAN);
      tft.fillRect(87,56,21,22,ST7735_CYAN);
      break;
    case('r'):
      tft.fillTriangle(50, 120, 50, 100, 30, 110 , ST7735_BLACK);
      tft.fillTriangle(80, 120, 80, 100, 100, 110 , ST7735_BLUE);
      tft.drawLine(50, 112, 80, 112, ST7735_BLUE);
      tft.drawLine(50, 111, 80, 111, ST7735_BLUE);
      tft.drawLine(50, 110, 80, 110, ST7735_BLUE);
      tft.drawLine(50, 109, 80, 109, ST7735_BLUE);
      tft.drawLine(50, 108, 80, 108, ST7735_BLUE);   
      break;    
    case('l'):
      tft.fillTriangle(80, 120, 80, 100, 100, 110 , ST7735_BLACK);
      tft.fillTriangle(50, 120, 50, 100, 30, 110 , ST7735_BLUE);
      tft.drawLine(50, 112, 80, 112, ST7735_BLUE);
      tft.drawLine(50, 111, 80, 111, ST7735_BLUE);
      tft.drawLine(50, 110, 80, 110, ST7735_BLUE);
      tft.drawLine(50, 109, 80, 109, ST7735_BLUE);
      tft.drawLine(50, 108, 80, 108, ST7735_BLUE); 
    break;
    case('m'):
      tft.fillTriangle(80, 120, 80, 100, 100, 110 , ST7735_BLACK);
      tft.fillTriangle(50, 120, 50, 100, 30, 110 , ST7735_BLACK);
      tft.drawLine(50, 112, 80, 112, ST7735_BLACK);
      tft.drawLine(50, 111, 80, 111, ST7735_BLACK);
      tft.drawLine(50, 110, 80, 110, ST7735_BLACK);
      tft.drawLine(50, 109, 80, 109, ST7735_BLACK);
      tft.drawLine(50, 108, 80, 108, ST7735_BLACK); 
  }
}

void loading(){
  tft.setCursor(50,64);
  tft.println("Pairing");
  while(!Serial.available()){
    tft.drawLine(95, 72, 96, 72, ST7735_WHITE);
    delay(500);
    tft.drawLine(98, 72, 99, 72, ST7735_WHITE);
    delay(500);
    tft.drawLine(101, 72, 102, 72, ST7735_WHITE);
    delay(500);
    tft.drawLine(95, 72, 96, 72, ST7735_BLACK);
    tft.drawLine(98, 72, 99, 72, ST7735_BLACK);
    tft.drawLine(101, 72, 102, 72, ST7735_BLACK);
    delay(500);
  }  
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(30,64);
  tft.println("Welcome Sweeper #1");
  delay(2000);
  tft.fillScreen(ST7735_BLACK);
}


void setup() {
  DisplayInit();
  tft.fillScreen(ST7735_BLACK);
  Serial.begin(115200); 
  delay(2000);  
  loading();



  command(); 
  intensityDirection(0);
}

void loop() {
  if(Serial.available()){
        uint8_t input = Serial.read();
        
        intensityDirection(input);
    }
  
}