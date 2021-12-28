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

void Int0Init(void){
    IT0 = 1;
    EX0 = 1;
    EA = 1;
}

void main(void){
    Int0Init();
	while(1){
		
	}
}

void Int0(void) interrupt 0{
    delay(1000);
    if(k3 == 0){
        led = ~led;
    }
}