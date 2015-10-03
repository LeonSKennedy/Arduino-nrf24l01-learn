/*
我们这里用到的库是 maiacbug 的 RF24，下载地址:
https://github.com/maniacbug/RF24
文档:
http://maniacbug.github.io/RF24/classRF24.html
*/

//导入RF24库
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
//这个是maniacbug 做的printf 用来输出文字 *不重要
#include "printf.h"

//初始 RF24(cePin, csnPi)
RF24 radio(9,10);

void setup(void)
{
  delay(5000);
  //开启serial port
  Serial.begin(57600);
  //运作芯片
  radio.begin();
  //开启printf 用来输出下面的测试
  printf_begin();  
  //输出测试
  radio.printDetails();
}

void loop(){
}
