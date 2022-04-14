/*
 * ws2812b
 * ESP8266驱动WS2812彩灯
 * 板载接口GPIO0
 */

#include <Adafruit_NeoPixel.h>

#define PIN        0  //GPIO0接口
#define NUMPIXELS  1  //彩灯个数

Adafruit_NeoPixel led(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  led.begin();
  led.setBrightness(10); //设置亮度 (0~255)
}

void loop() {
  
  led.setPixelColor(0,led.Color(255, 0, 0)); //红色
  led.show(); //刷新显示
  delay(1000);

  led.setPixelColor(0,led.Color(0, 255, 0)); //绿色
  led.show(); //刷新显示
  delay(1000);

  led.setPixelColor(0,led.Color(0, 0, 255)); //蓝色
  led.show(); //刷新显示
  delay(1000);
  
  led.clear();//清空显示
  led.show(); //刷新显示
  delay(1000);

}
