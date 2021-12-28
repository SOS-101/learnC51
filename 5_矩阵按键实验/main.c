#include "reg51.h"
#include "intrins.h"

typedef unsigned char u8;
typedef unsigned int u16;

#define GPIO_DIG P0
#define GPIO_KEY P1

u8 keyvalue;

sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

//when i=1, delay 10us
void delay(u16 i){
    while(i--){
    }
}

void keydown(void){
    u8 i;
    GPIO_KEY = 0x0f;
    if(GPIO_KEY != 0x0f){
        delay(1000);
        if(GPIO_KEY!=0x0f){
            GPIO_KEY=0x0f;
            switch(GPIO_KEY){
                case 0x07:
                    keyvalue = 0;
                    break;
                case 0x0b:
                    keyvalue = 1;
                    break;
                case 0x0d:
                    keyvalue = 2;
                    break;
                case 0x0e:
                    keyvalue = 3;
                    break;
            }
            GPIO_KEY = 0xf0;
            switch(GPIO_KEY){
                case 0x70:
                    keyvalue = keyvalue;
                    break;
                case 0xb0:
                    keyvalue += 4;
                    break;
                case 0xd0:
                    keyvalue += 8;
                    break;
                case 0xe0:
                    keyvalue += 12;
                    break;      
            }
        }
        while((i<50)&&(GPIO_KEY!=0xf0)){
            delay(100);
            i++;
        }
    }
}

void main(void){
	while(1){
        keydown();
        GPIO_DIG = smgduan[keyvalue];	
	}
}