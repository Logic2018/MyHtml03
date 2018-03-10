#include<reg51.h>
sbit P1_0=P1^0;
turn()interrupt 1	//1号中断控制T0
{
	P1_0=!P1_0;		//计时满溢取反	
	TH0=0xff;			//载入初值
	TL0=0x9c;	
	TF0=0;
}
void main(){
	P1_0=0;
	TMOD=0x05;		//设置工作方式
	EA=1;					//打开总中断
	ET0=1;				//打开T0中断		
	TH0=0xff;			//载入初值
	TL0=0x9c;
	TR0=1;				//打开定时器T0
while(1);	
}



