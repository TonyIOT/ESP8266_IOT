/*
 * oled_infor
 * OLED显示连网信息
 */
#include <ESP8266WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const char* ssid     = "your-ssid";//连接WIFI名(SSID)
const char* password = "your-password";//WIFI密码

Adafruit_SSD1306 oled(128, 64, &Wire,-1);

void setup()
{
  oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
  oled.setTextColor(WHITE);//开像素点发光
  oled.clearDisplay();//清屏
  
  oled.setTextSize(1); //设置字体大小  
  oled.setCursor(15, 5);//设置显示位置
  oled.println("WiFi Information");
  oled.setCursor(2, 20);//设置显示位置

  WiFi.begin(ssid,password);//启动网络连接

  while (WiFi.status() != WL_CONNECTED)//检测网络是否连接成功
  {
    delay(500);
    oled.print(".");//设置显示位置
    oled.display(); // 开显示
  }
  
  oled.setTextSize(1);//设置字体大小  
  oled.setCursor(2, 35);//设置显示位置
  oled.println("Connected,IP address:");
  oled.println();
  oled.println(WiFi.localIP());
  oled.display(); // 开显示
}

void loop() {}
