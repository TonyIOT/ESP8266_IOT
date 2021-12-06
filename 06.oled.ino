/*
 * oled
 * ESP8266驱动OLED屏
 */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(128, 64, &Wire,-1);

void setup()
{
  oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
  oled.setTextColor(WHITE);//开像素点发光
  oled.clearDisplay();//清屏
  
  oled.setTextSize(1); //设置字体大小  
  oled.setCursor(35, 5);//设置显示位置
  oled.println("-TonyCode-");

  oled.setTextSize(2);//设置字体大小  
  oled.setCursor(15, 30);//设置显示位置
  oled.println("OLED TEST");
  
  oled.display(); // 开显示
}

void loop() {}
