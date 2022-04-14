/*
 * dht11
 * ESP8266驱动DHT11温湿度传感器 
 * OLED显示
 */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"

#define DHT_Pin 14  //控制引脚
#define DHTTYPE DHT11 //传感器类型 DHT11 DHT21 DHT22

DHT dht(DHT_Pin, DHTTYPE);
Adafruit_SSD1306 oled(128, 64, &Wire,-1);

void setup() {
  oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
  oled.setTextColor(WHITE);//开像素点发光
  oled.clearDisplay();//清屏 
  oled.setTextSize(2); //设置字体大小
  oled.display(); // 开显示
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  oled.clearDisplay();//清屏 
  oled.setCursor(10, 10);//设置显示位置
  oled.print("T:");
  oled.print(t);
  oled.println(" C");
  oled.setCursor(10, 40);//设置显示位置
  oled.print("H:"); 
  oled.print(h);
  oled.println(" %");
  oled.display(); // 开显示
  delay(1000);
}
