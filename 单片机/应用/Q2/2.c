#include<reg51.h>
sbit key=P3^0;
unsigned char code LED[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};   //CA 共阳
//unsigned char code LED[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; //cc
unsigned char buf[4];					//存放当前LED的4位数
unsigned int Q=1560;					//设定需要消耗1560kJ热量
unsigned int i=0;
void delay(unsigned char x){
	while(1){
		TR0=1;
		do{}while(!TF0);
		if(++i%x==0)		
			break;
		TF0=0;
	}
}
count() interrupt 3{
	 Q-=3;
	 TF1=0;
}
init0() interrupt 0{
	 Q = 1560;
}
void display(unsigned int temp){//LED显示
	unsigned char i;
	buf[0]=temp/1000;			//分离数值位
	buf[1]=temp%1000/100;
	buf[2]=temp%100/10;
	buf[3]=temp%10;
	for(i=0;i<4;i++){			//循环显示
		P2=(0x01<<i);				//选位信号
		P1=LED[buf[i]];			//显示数值
		delay(40);					//延迟
		P1=0xff;						//消隐
	}
}
void main(){
	EA=1;		//打开总中断
	EX0=1;  //打开INT0中断
	ET1=1;	//打开定时器T1中断
	IT1=0;  //设置INT0位触发方式位低电平
		
	TMOD=0x62;  //设置工作方式
	TL0=0x06;		//T0定时器装载初值0.25ms
	TH0=TL0;
	
	TL1=0xf6;		//T1计数器装载初值246 ，256满溢
	TH1=TL1;
  while(1){
    display(Q);	//调用显示函数
		TR1=1;		  //打开计数器
	}
}