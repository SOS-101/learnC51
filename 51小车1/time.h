#include"reg51.h"
#include"intrins.h"
void timer0()interrupt 1
{
	TH0=(65536-120)/256;
	TL0=(65536-120)%256;
	count1++;
	if(count1>1000)
		count1=0;
}
void timer1()interrupt 3
{
	TH1=(65536-120)/256;
	TL1=(65536-120)%256;
	count2++;
	if(count2>=1000)
		count2=0;
}