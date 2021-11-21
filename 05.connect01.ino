/*
 * connect01
 * ESP8266连接网络
 */
#include <ESP8266WiFi.h>

const char* ssid     = "your-ssid";//连接WIFI名(SSID)
const char* password = "your-password";//WIFI密码

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("--------------");
  
  WiFi.begin(ssid,password);//启动网络连接

  Serial.printf("Begin to Connect %s\r\n", ssid);
  while (WiFi.status() != WL_CONNECTED)//检测网络是否连接成功
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());//返回ESP8266的IP地址
}

void loop() {}
