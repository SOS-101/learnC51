#include"reg51.h"
void left_motor(int count1,int time1)
{
	IN1=1;
	IN2=0;
	if ( count1<time1)
	ENA=1;
	else
	ENA=0;
}
void right_motor(int count2,int time2)
{
	IN3=0;
	IN4=1;
	if ( count2<time2)
		ENB=1;
	else
		ENB=0;
}
void back_left(int count1,int time1)
{
	IN1=0;
	IN2=1;
	if(count1<time1)
		ENA=1;
	else
		ENA=0;
}
void back_right(int count2,int time2)
{
	IN3=1;
	IN4=0;
	if ( count2<time2)
		ENB=1;
	else
		ENB=0;
}
void straight(int count1,int time1,int count2,int time2)
{
	right_motor(count2,time2);
	left_motor(count1,time1);
}
void acute_left(int count1,int time1,int count2,int time2)
{
	back_left(count1,time1);
	right_motor(count2,time2);
}
void acute_right(int count1,int time1,int count2,int time2)
{
	left_motor(count1,time1);
	back_right(count2,time2);
}
