#include<reg51.h>
sbit P1_0=P1^0;
turn()interrupt 1	//1���жϿ���T0
{
	P1_0=!P1_0;		//��ʱ����ȡ��	
	TH0=0xff;			//�����ֵ
	TL0=0x9c;	
	TF0=0;
}
void main(){
	P1_0=0;
	TMOD=0x05;		//���ù�����ʽ
	EA=1;					//�����ж�
	ET0=1;				//��T0�ж�		
	TH0=0xff;			//�����ֵ
	TL0=0x9c;
	TR0=1;				//�򿪶�ʱ��T0
while(1);	
}



