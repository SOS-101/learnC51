#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit PWM = P2^1;
bit DIR;

u16 count,value,timer1;

void Timer1Init(void){
    TMOD|=0x10;

    TH1 = 0xff;
    TF1 = 0xff; //1us

    ET1 = 1;
    EA = 1;
    TR1 = 1;
}

void main(void){
    Timer1Init();
	while(1){
	    if(count>100){
            count = 0;
            if(DIR==1){
                value++;
            }
            if(DIR==0){
                value--;
            }
        }
        if(value == 1000){
            DIR = 0;
        }	
        if(value==0){
            DIR = 1;
        }
        if(timer1>1000){
            timer1 = 0;
        }
        if(timer1<value){
            PWM = 1;
        }
        else{
            PWM = 0;
        }
	}
}

void Time1(void) interrupt 3{
    TH1 = 0xff;
    TL1 = 0xff;
    timer1++;
    count++;
}