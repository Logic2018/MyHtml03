/*
#include<reg51.h>
sbit key=P3^3;
unsigned char code LED[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};   //CA ������
unsigned char code LEDp[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};  //��С���㹲����
unsigned char buf[4]={0};					//��ŵ�ǰLED��4λ��
unsigned int i=0;
void delay(unsigned char x){			//�ӳٺ���
	while(1){
		TR0=1;
		do{}while(!TF0);
		if(++i%x==0)		
			break;
		TF0=0;
	}
}
void display(){										//LED��ʾ
	unsigned char i;
	for(i=0;i<4;i++){			//ѭ����ʾ
		P2=(0x01<<i);				//ѡλ�ź�
		if(P2==0x02)
			P1=LEDp[buf[i]];		//��2λ��������ʾ����
		else 
			P1=LED[buf[i]];			//��ʾ��ֵ
		delay(2);						  //�ӳ�0.5ms
		P1=0xff;						  //����
	}
}
init0() interrupt 0{   // ��ʼ��Ϊ0
	  buf[3]=0;
		buf[2]=0;
		buf[1]=0;
		buf[0]=0;
}
pause() interrupt 2{	// ��ͣ�ж�
	  while(1){
			display();
			if(key)break;
		}
}
init() interrupt 3{				//����ʾ���ֵĳ�ʼ��
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
	EA=1;		//�����ж�
	EX0=1;  //��INT0�ж�
	EX1=1;  //��INT1�ж�
	ET1=1;	//�򿪶�ʱ��T1�ж�
	IT0=0;  //����INT0λ������ʽλ�͵�ƽ
	IT1=0;  //����INT1λ������ʽλ�͵�ƽ	
	TMOD=0x60;
  TL1=0xf6;		//T1������װ�س�ֵ256 ��256����
	TH1=TL1;
  while(1){
    display();	//������ʾ����
		TR1=1;		  //�򿪼�����
	}
}*/