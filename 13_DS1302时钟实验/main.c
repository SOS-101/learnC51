#include "reg51.h"
#include "intrins.h"
#include "ds1302.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
char num = 0;
u8 DisplayData[8];

//when i=1, delay 10us
void delay(u16 i){
    while(i--){
    }
}

void datapros(void){
    Ds1302ReadTime();
    DisplayData[0] = smgduan[TIME[2]/16];
    DisplayData[1] = smgduan[TIME[2]&0x0f];
    DisplayData[2] = 0x40;
    DisplayData[3] = smgduan[TIME[1]/16];
    DisplayData[4] = smgduan[TIME[1]&0x0f];
    DisplayData[5] = 0x40;
    DisplayData[6] = smgduan[TIME[0]/16];
    DisplayData[7] = smgduan[TIME[0]&0x0f];
}

void DigDisplay(void){
    u8 i;
    for(i = 0;i < 8;i++){
        switch(i){
            case 0:
                LSA = 1;
                LSB = 1;
                LSC = 1;
                break;
            case 1:
                LSA = 0;
                LSB = 1;
                LSC = 1;
                break;
            case 2:
                LSA = 1;
                LSB = 0;
                LSC = 1;
                break;
            case 3:
                LSA = 0;
                LSB = 0;
                LSC = 1;
                break;
             case 4:
                LSA = 1;
                LSB = 1;
                LSC = 0;
                break;
             case 5:
                LSA = 0;
                LSB = 1;
                LSC = 0;
                break;
             case 6:
                LSA = 1;
                LSB = 0;
                LSC = 0;
                break;
             case 7:
                LSA = 0;
                LSB = 0;
                LSC = 0;
                break;

        }
        P0 = DisplayData[i];
        delay(100);
        P0 = 0x00;
    }
}

void main(void){
    Ds1302Init();
	while(1){
        datapros();
        DigDisplay();	
	}
}