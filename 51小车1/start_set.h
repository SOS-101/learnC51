#include"reg51.h"
sbit ENA=P0^0;
sbit IN1=P0^1;
sbit IN2=P0^2;
sbit ENB=P1^0;
sbit IN3=P1^1;
sbit IN4=P1^2;
sbit left1=P2^3;
sbit left2=P2^4;
sbit right1=P2^1;
sbit right2=P2^2;
int count1=0;
int count2=0;
void time_start(void)
{
	TMOD=0x00;
	TH0=(65536-120)/256;
	TL0=(65536-120)%256;
	EA=1;
	ET0=1;
	TR0=1;
	TH1=(65536-120)/256;
	TL1=(65536-120)%256;
	EA=1;
	ET1=1;
	TR1=1;
}