#include<reg51.h>
sbit key=P3^0;
unsigned char code LED[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};   //CA ����
//unsigned char code LED[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; //cc
unsigned char buf[4];					//��ŵ�ǰLED��4λ��
unsigned int Q=1560;					//�趨��Ҫ����1560kJ����
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
void display(unsigned int temp){//LED��ʾ
	unsigned char i;
	buf[0]=temp/1000;			//������ֵλ
	buf[1]=temp%1000/100;
	buf[2]=temp%100/10;
	buf[3]=temp%10;
	for(i=0;i<4;i++){			//ѭ����ʾ
		P2=(0x01<<i);				//ѡλ�ź�
		P1=LED[buf[i]];			//��ʾ��ֵ
		delay(40);					//�ӳ�
		P1=0xff;						//����
	}
}
void main(){
	EA=1;		//�����ж�
	EX0=1;  //��INT0�ж�
	ET1=1;	//�򿪶�ʱ��T1�ж�
	IT1=0;  //����INT0λ������ʽλ�͵�ƽ
		
	TMOD=0x62;  //���ù�����ʽ
	TL0=0x06;		//T0��ʱ��װ�س�ֵ0.25ms
	TH0=TL0;
	
	TL1=0xf6;		//T1������װ�س�ֵ246 ��256����
	TH1=TL1;
  while(1){
    display(Q);	//������ʾ����
		TR1=1;		  //�򿪼�����
	}
}