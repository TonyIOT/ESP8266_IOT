/*
 * gpio
 * ESP8266的IO口功能
 * 通过板载在资源熟悉ESP8266的IO功能
 * 1.数字输出——继电器 LED灯
 * 2.数字输入——按键
 * 3.模拟输入——光敏电阻
 * 4.模拟输出——电机PWM控制
 */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 oled(128, 64, &Wire,-1);

#define Relay_Pin   15  //继电器控制引脚
#define Led_Pin     2   //模块指示灯
#define Key_Pin     16  //按键控制引脚
#define Light_Pin   A0  //光敏电阻引脚
#define MotorA_Pin  12  //电机引脚A
#define MotorB_Pin  13  //电机引脚B

int key_sta = 0;

void motorTest(void)
{
  //加速正转
  analogWrite(MotorB_Pin, 0);
  for(int i=10;i<30;i++)
  {
    analogWrite(MotorA_Pin, i);
    delay(10);
  }

  //减速反转
  analogWrite(MotorA_Pin, 0);
   for(int i=30;i>10;i--)
  {
    analogWrite(MotorB_Pin, i);
    delay(10);
  }
}

//按键检测
char keyCheck(void)
{	 
	static char key_up=1;//按键松开
	if(key_up&&(digitalRead(Key_Pin)==HIGH))
	{
		delay(10);//去抖动 
		key_up=0;
		if(digitalRead(Key_Pin)==HIGH)return 1;
	}else if(digitalRead(Key_Pin)==LOW)key_up=1; 	    
 	return 0;// 无按键按下
}

void setup()
{
  pinMode(Relay_Pin,  OUTPUT);  //输出模式
  pinMode(Led_Pin,  OUTPUT);  //输出模式
  pinMode(Key_Pin, INPUT_PULLDOWN_16); //下拉输入
  pinMode(MotorA_Pin,  OUTPUT); //输出模式
  pinMode(MotorB_Pin,  OUTPUT); //输出模式

  digitalWrite(Relay_Pin, LOW);//继电器关闭
  digitalWrite(Led_Pin, HIGH);//指示灯关闭

  oled.begin(SSD1306_SWITCHCAPVCC,0x3C);
  oled.setTextColor(WHITE);//开像素点发光
  oled.clearDisplay();//清屏
  oled.setTextSize(2); //设置字体大小  
}

void loop() 
{
 // motorTest(); //电机PWM测试

  if(keyCheck()==1)
  {
    key_sta = !key_sta;
    digitalWrite(Relay_Pin, key_sta);
    digitalWrite(Led_Pin, !key_sta);
  }
  
  oled.clearDisplay();//清屏
  oled.setCursor(15, 5);//设置显示位置
  oled.print("ADC:");
  oled.print(analogRead(A0)); //A0引脚ADC值 范围0~1023
  oled.setCursor(15, 40);//设置显示位置
  oled.print("STA:");
  oled.println(key_sta==1 ? "OPEN" : "CLOSE"); //继电器 LED开关状态
  oled.display(); // 开显示
}
