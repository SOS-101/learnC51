#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit k3 = P3^2;
sbit led = P2^0;

//when i=1, delay 10us
void delay(u16 i){
    while(i--){
    }
}

void Timer0Init(void){
    TMOD |= 0x01;
    TH0 = 0xfc; //1 ms
    TL0 = 0x18;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
}

void main(void){
    Timer0Init();
	while(1){
		
	}
}

void Timer0(void) interrupt 1{
    static u16 i;
    TH0 = 0xfc;
    TL0 = 0x18;
    i++;
    if(i==1000){
        i = 0;
        led = ~led;
    }    
}