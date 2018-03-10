#include<reg51.h>
sbit P1_0=P1^0;
sbit P0_0=P0^0;
char i=0;
turn0()interrupt 1	  //1号中断控制T0
{
		P1_0=!P1_0;		//计时满溢取反	
		TH0=0xfe;			//T0载入初值
		TL0=0x0c;	
}
turn1() interrupt 3{  //3号中断控制T1
	i++;
	if(i%10==0)
	  P0_0 =!P0_0 ;
}
void main(){
	TMOD=0x61;		//设置工作方式
	EA=1;					//打开总中断
	ET0=1;				//打开T0中断		
	TH0=0xfe;			//定时器T0载入初值
	TL0=0x0c;

	TL1=0x9c;		  //计数器T1载入初值
	TH1=TL1;
	ET1=1;			  //打开T1中断
		
	TR0=1;				//打开定时器T0
	TR1=1;			  //打开计数器T1		
while(1);	
}