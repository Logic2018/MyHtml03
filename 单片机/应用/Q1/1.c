#include<reg51.h>
char led[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf};
bit dir=0,run=0;
unsigned int i=0;
unsigned int t=1000;		 		  //默认1ms*1000
void delay(unsigned int t){	  //延时1ms*t
	TMOD=0x01;	      //T0的方式1
	while(1){
		TH0=0xfc;				//定时1ms
		TL0=0x18;
		TR0=1;				  //打开定时器
		while(!TF0);		//查询是否计时结束
		if(++i%t==0)		//	#1	
			break;
		TF0=0;
	}
}
key()interrupt 0{
	switch(P0&0x0f){			//开关控制
		case 0x0e:run=1;dir=0;break;//从下到上
		case 0x0d:run=1;dir=1;break;//从上到下
		case 0x0b:t=t/2;break;
		case 0x07:dir=0;run=0;break;
	}
}
void main(){
	char i;
	EA=1;            //打开总中断
	EX0=1;           //打开INT0中断
	IT0=1;					 //INT0采用边沿触发方式
	
				
	while(1){
		P2=0x2a;				//彩灯实现交替闪烁
		if(run){				//流水灯	
			if(dir) 
				for( i=0;i<=5;i++){	//从下到上
					P2=led[i];
					delay(t);
				}
			else	  
				for(i=5;i>=0;i--){  //从上到下
					P2=led[i];
					delay(t);
			}
		}		
		P2=0x15;				//彩灯实现交替闪烁
	}
}