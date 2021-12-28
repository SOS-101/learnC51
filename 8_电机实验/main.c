#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit moto = P1^0;

//when i=1, delay 10us
void delay(u16 i){
    while(i--){
    }
}

void main(void){
    u8 i;
    moto = 0;
    for(i=0;i<100;i++){
        moto = 1;
        delay(5000);
    }
    moto = 0;
	while(1){
		
	}
}