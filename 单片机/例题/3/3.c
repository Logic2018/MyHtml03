#include<reg51.h>
sbit P1_0=P1^0;
void main(){
	TMOD=0x02;			//设置工作方式
	TH0=0x06;			  //载入初值
	TL0=TH0;
	while(1){
		TR0=1;				//启动定时器T0
		while(!TF0);	//查询TF0置位
		P1_0=!P1_0;		//计时满溢取反
		TF0=0;				//软件TF0清0	
	}
}

/*
#include<reg51.h>
sbit P1_0=P1^0;
turn()interrupt 1	//1号中断控制T0
{
		P1_0=!P1_0;		//计时满溢取反	
}
void main(){
		TMOD=0x02;		//设置工作方式
		EA=1;					//打开总中断
		ET0=1;				//打开T0中断		
		TH0=0x06;			//载入初值
		TL0=TH0;
 	  TR0=1;				//打开定时器T0
    while(1);	
}*/