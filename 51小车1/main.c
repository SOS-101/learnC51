#include "reg51.h"
#include"start_set.h"
#include"motor.h"
#include"time.h"
void main()
{
time_start();
while(1)
	{
	if(left2==0&&left1==0&&right1==0&&right2==0)//?㊣DD
		straight(count1,650,count2,650);
	else if(left2==0&&left1==1&&right1==0&&right2==0)//℅車D?℅a
		straight(count1,1,count2,1000);
	else if(left2==0&&left1==0&&right1==1&&right2==0)//車辰D?℅a
		straight(count1,1000,count2,1);
	else if(left2==1&&left1==1&&right1==0&&right2==0)//℅車∩車℅a
		acute_left(count1,800,count2,800);
	else if(left2==0&&left1==0&&right1==1&&right2==1)//車辰∩車℅a
		acute_right(count1,800,count2,800);
	else if(left2==1&&left1==0&&right1==0&&right2==0)//℅車?㊣℅a
		{
			acute_left(count1,1000,count2,1000);
		}
	else if(left2==0&&left1==0&&right1==0&&right2==1)//車辰?㊣℅a
		{
			acute_right(count1,1000,count2,1000);
		}
	}
}



