#include "reg51.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit beep = P1^5;

//when i=1, delay 10us
void delay(u16 i){
    while(i--){
    }
}

void main(void){
	while(1){
        beep = 0;
        delay(50);
        beep = ~beep;	
	}
}