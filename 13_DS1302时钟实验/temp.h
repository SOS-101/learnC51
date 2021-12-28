#ifndef __TEMP_H_
#define __TEMP_H_

#include "reg51.h"

typedef unsigned char u8;
typedef unsigned int u16;

sbit DSPORT = P3^7;

void Delay1ms(u16);
u8 Ds18b20Init(void);
void Ds18b20WriteByte(u8 dat);
u8 Ds18b20ReadByte(void);
void Ds18b20ChangeTemp(void);
void Ds18b20ReadTempCom(void);
int Ds18b20ReadTemp(void);

#endif