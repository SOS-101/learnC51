#include "reg51.h"
#include "i2c.h"

sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;
sbit k1 = P3^1;
sbit k2 = P3^0;
sbit k3 = P3^2;
sbit k4 = P3^3;

u8 dat=0;
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f};
u8 disp[4];

//when i=1, delay 10us
void delay(u16 i){
    while(i--){
    }
}

void Keypros(void){
    if(k1==0){
        delay(1000);
        if(k1==0){
            At24c02Write(1,dat);    
        }
        while(!k1);
    }
    if(k2==0){
        delay(1000);
        if(k2==0){
            dat = At24c02Read(1);    
        }
        while(!k2);
    }
    if(k3==0){
        delay(1000);
        if(k3==0){
            dat++;
            if(dat>255){
                dat = 0;
            }        
        }
        while(!k3);
    }
    if(k4==4){
        delay(1000);
        if(k4==0){
            dat = 0;    
        }
        while(!k4);
    }
}

void Datpros(void){
    disp[0]=smgduan[dat/1000];
    disp[1]=smgduan[dat%1000/100];
    disp[2]=smgduan[dat%1000%100/10];
    disp[3]=smgduan[dat%1000%100%10];
}

void DigDisplay(void){
    u8 i;
    for(i = 0;i < 4;i++){
        switch(i){
            case 0:
                LSA = 1;
                LSB = 1;
                LSC = 0;
                break;
            case 1:
                LSA = 0;
                LSB = 1;
                LSC = 0;
                break;
            case 2:
                LSA = 1;
                LSB = 0;
                LSC = 0;
                break;
            case 3:
                LSA = 0;
                LSB = 0;
                LSC = 0;
                break;
        }
        P0 = disp[i];
        delay(100);
        P0 = 0x00;
    }
}

void main(void){
	while(1){
        Keypros();
        Datpros();
        DigDisplay();	
	}
}