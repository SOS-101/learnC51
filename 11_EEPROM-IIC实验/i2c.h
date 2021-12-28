#ifndef __I2C_H_
#define __I2C_H_

#include <reg51.h>
#include <intrins.h>

typedef unsigned int u16;
typedef unsigned char u8;

sbit SCL = P2^1;
sbit SDA = P2^0;

void delay10us(void);
void I2cStart(void);
void I2cStop(void);
u8 I2cSendByte(u8 dat);
u8 I2cReadByte(void);
void At24c02Write(u8 addr,u8 dat);
u8 At24c02Read(u8 addr);

#endif