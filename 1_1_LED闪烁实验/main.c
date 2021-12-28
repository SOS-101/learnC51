#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P2^0;

//when i=1, delay 10us
void delay(u16 i){
    while(i--){
    }
}

void main(void){
    led = 0;
	while(1){
        delay(50000);
        led = ~led;	
	}
}