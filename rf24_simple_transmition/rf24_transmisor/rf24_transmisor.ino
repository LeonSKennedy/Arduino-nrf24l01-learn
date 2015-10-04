/*
作者：tmirun
我们这里用到的库是 maiacbug 的 RF24，下载地址:
https://github.com/maniacbug/RF24
文档:
http://maniacbug.github.io/RF24/classRF24.html
*/

//导入RF24库
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

//初始 RF24(cePin, csnPi)
RF24 radio(9,10);

//这个是我们即将建立的传输渠道编码
//!!要和另一个模块的一致
const uint64_t pipe = 0xE8E8F0F0E1LL;

//要传输的数据
int data = 0;

void setup(void){
  Serial.begin(57600);
  //启动芯片
  radio.begin();
  //打开写入通道
  radio.openWritingPipe(pipe);
}

void loop(void)
{
      Serial.print("Sending:");
      Serial.print(data);
      
      //调用radio.write(const void *buf, uint8_t len)传递信息
      //第一个参数是我们要传递的变量指针，第二个参数是要传输的信息大小.
      //如果传输成功会返回true 否则返回false.
      bool ok = radio.write(&data,sizeof(int));
      if(ok)
        Serial.println(".....successed");
      else
        Serial.println(".....failed");

      data++;
      delay(200);
}
