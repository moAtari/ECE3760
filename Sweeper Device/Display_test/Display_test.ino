#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);  

void initOLED(){
  u8g2.begin();
  u8g2.enableUTF8Print();		// enable UTF8 support for the Arduino print() function  
  
}

void setup() {
  initOLED();
  
}

void loop() {
  u8g2.setFont(u8g2_font_unifont_t_chinese2);  // use chinese2 for all the glyphs of "你好世界"
  u8g2.setFontDirection(0);
  u8g2.clearBuffer();
  u8g2.setCursor(0, 15);
  u8g2.print("Sweep this way:");
  u8g2.setFont(u8g2_font_open_iconic_arrow_2x_t);
  u8g2.setCursor(50, 50);
  u8g2.print("\u0041");		// Chinese "Hello World" 
  u8g2.sendBuffer();
  
  delay(1000);

}
