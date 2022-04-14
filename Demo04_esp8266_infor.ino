/*
 * Demo01
 * 打印ESP8266模块信息
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("------------------");
  Serial.printf("The Chip ID:0x%X\r\n", ESP.getChipId()); //获取芯片ID
  Serial.printf("The Core Version:%s\r\n", ESP.getCoreVersion());//获取核心库版本
  Serial.printf("The SDK Version:%s\r\n", ESP.getSdkVersion());//获取SDK版本
  Serial.printf("The CPU Freq:%d MHz\r\n", ESP.getCpuFreqMHz());//获取CPU运行频率
  Serial.println("------------------");
  Serial.printf("The Flash Chip ID:0x%X\r\n", ESP.getFlashChipId());//获取闪存ID
  Serial.printf("The Flash Real Size:%d KBytes\r\n", ESP.getFlashChipRealSize()/1024);//获取闪存容量
  Serial.printf("The Flash Chip Speed:%d MHz\r\n", ESP.getFlashChipSpeed()/1000000);//获取闪存芯片运行频率
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
