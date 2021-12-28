#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit led = P2^0;
sbit k1 = P3^1;

//when i=1, delay 10us
void delay(u16 i){
    while(i--){
    }
}

void keypros(void){
    if(k1 == 0){
        delay(1000);
        if(k1 == 0){
            led = ~led;
        }
        while(!k1);
    }
}

void main(void){
	while(1){
	    keypros();	
	}
}