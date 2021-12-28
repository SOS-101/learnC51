#include <i2c.h>

void delay10us(void){
    unsigned char a,b; 
    for(b=1;b>0;b--){ 
        for(a=2;a>0;a--);    
    }
}

void I2cStart(void){
    SDA = 1;
    delay10us();
    SCL = 1;
    delay10us();
    SDA = 0;
    delay10us();
    SCL = 0;
    delay10us();    
}

void I2cStop(void){
    SDA = 0;
    delay10us();
    SCL = 1;
    delay10us();
    SDA = 1;
    delay10us();
}

u8 I2cSendByte(u8 dat){
    u8 i=0,j=0;
    for(i=0;i<8;i++){
        SDA = dat >> 7;
        dat = dat << 1;
        delay10us();
        SCL = 1;
        delay10us();
        SCL = 0;
        delay10us();
    }
    SDA = 1;
    delay10us();
    SCL = 1;
    while(SDA){
        j++;
        if(j>200){
            SCL = 0;
            delay10us();
            return 0;
        }
    }
    SCL = 0;
    delay10us();
    return 1;    
}

u8 I2cReadByte(void){
    u8 i=0,dat = 0;
    SDA = 1;
    delay10us();
    for(i=0;i<8;i++){
        SCL = 1;
        delay10us();
        dat <<= 1;
        dat |= SDA;
        delay10us();
        SCL = 0;
        delay10us();
    }
    return dat;
}

void At24c02Write(u8 addr,u8 dat){
    I2cStart();
    I2cSendByte(0xa0);
    I2cSendByte(addr);
    I2cSendByte(dat);
    I2cStop();    
}

u8 At24c02Read(u8 addr){
    u8 dat;
    I2cStart();
    I2cSendByte(0xa0);
    I2cSendByte(addr);
    I2cStart();
    I2cSendByte(0xa1);
    dat = I2cReadByte();
    I2cStop();
    return dat;
}