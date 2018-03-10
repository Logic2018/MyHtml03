/*
#include<reg51.h>
sbit key=P3^3;
unsigned char code LED[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};   //CA 共阳码
unsigned char code LEDp[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};  //带小数点共阳码
unsigned char buf[4]={0};					//存放当前LED的4位数
unsigned int i=0;
void delay(unsigned char x){			//延迟函数
	while(1){
		TR0=1;
		do{}while(!TF0);
		if(++i%x==0)		
			break;
		TF0=0;
	}
}
void display(){										//LED显示
	unsigned char i;
	for(i=0;i<4;i++){			//循环显示
		P2=(0x01<<i);				//选位信号
		if(P2==0x02)
			P1=LEDp[buf[i]];		//第2位带点现显示数字
		else 
			P1=LED[buf[i]];			//显示数值
		delay(2);						  //延迟0.5ms
		P1=0xff;						  //消隐
	}
}
init0() interrupt 0{   // 初始化为0
	  buf[3]=0;
		buf[2]=0;
		buf[1]=0;
		buf[0]=0;
}
pause() interrupt 2{	// 暂停中断
	  while(1){
			display();
			if(key)break;
		}
}
init() interrupt 3{				//待显示数字的初始化
	buf[3]++;
	if(buf[3]==10){
		buf[3]=0;
		buf[2]++;
	}
	if(buf[2]==10){
		buf[2]=0;
		buf[1]++;
	}
	if(buf[1]==10){
		buf[1]=0;
		buf[0]++;
	}
	if(buf[0]==10){
		buf[3]=0;
		buf[2]=0;
		buf[1]=0;
		buf[0]=0;
	}
	TF1=0;
}
void main(){
	EA=1;		//打开总中断
	EX0=1;  //打开INT0中断
	EX1=1;  //打开INT1中断
	ET1=1;	//打开定时器T1中断
	IT0=0;  //设置INT0位触发方式位低电平
	IT1=0;  //设置INT1位触发方式位低电平	
	TMOD=0x60;
  TL1=0xf6;		//T1计数器装载初值256 ，256满溢
	TH1=TL1;
  while(1){
    display();	//调用显示函数
		TR1=1;		  //打开计数器
	}
}*/