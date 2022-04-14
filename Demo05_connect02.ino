/*
 * connect02
 * ESP8266在多个热点中寻找信号最强的进行连接
 */
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifis;//建立ESP8266WiFiMulti对象

void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println("--------------");

  //添加多个热点信息
  wifis.addAP("TonyCode", "12345678");
  wifis.addAP("TonyCode1","12123455");
  wifis.addAP("TonyCode2","88888888");
  wifis.addAP("TonyCode3","66666666");
  
  Serial.println("Begin to Connect");
  while (wifis.run() != WL_CONNECTED)//检测网络是否连接成功
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.printf("Connected %s, IP address: ", WiFi.SSID());
  Serial.println(WiFi.localIP());//返回ESP8266的IP地址
}

void loop() {}
