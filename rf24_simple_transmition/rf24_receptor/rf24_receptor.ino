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

//这个变量会保持我们接受到的信息
//!!变量类型一定要和传过来的一样
int recibeData;

void setup(void){
  Serial.begin(57600);
  //启动芯片
  radio.begin();
  //打开窃听通道
  radio.openReadingPipe(1,pipe);
  //开始窃听
  radio.startListening();
}

void loop(void){
  //用available方法来看是否有信息要接受 
  if (radio.available()){
    Serial.print("recibe:");
    //调用radia.read(const void *buf, uint8_t len)来接受信息
    //第一个参数是我们要保持信息的变量指针, 第二个参数是要接受的信息大小
    radio.read( &recibeData, sizeof(int));     
    Serial.println(recibeData);
  }
}
