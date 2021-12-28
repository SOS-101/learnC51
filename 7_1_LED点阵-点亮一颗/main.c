#include "reg51.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit SCLK = P3^6;
sbit RCLK = P3^5;
sbit SER = P3^4;
sbit LED = P0^7;

//when i=1, delay 10us
void delay(u16 i){
    while(i--){
    }
}

void HC595SendByte(u8 dat1){
    u8 i;
    SCLK = 1;
    RCLK = 1;
    for(i=0;i<8;i++){
        SER = dat1 >> 7;
        dat1 <<=1;
        SCLK = 0;
        _nop_();
        _nop_();
        SCLK = 1;
    }
    
    RCLK = 0;
    _nop_();
    _nop_();
    RCLK = 1;
}

void main(void){
    LED = 0;
	while(1){
        HC595SendByte(0x01);
	}
}