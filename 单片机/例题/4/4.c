#include<reg51.h>
sbit P1_0=P1^0;
sbit P0_0=P0^0;
char i=0;
turn0()interrupt 1	  //1���жϿ���T0
{
		P1_0=!P1_0;		//��ʱ����ȡ��	
		TH0=0xfe;			//T0�����ֵ
		TL0=0x0c;	
}
turn1() interrupt 3{  //3���жϿ���T1
	i++;
	if(i%10==0)
	  P0_0 =!P0_0 ;
}
void main(){
	TMOD=0x61;		//���ù�����ʽ
	EA=1;					//�����ж�
	ET0=1;				//��T0�ж�		
	TH0=0xfe;			//��ʱ��T0�����ֵ
	TL0=0x0c;

	TL1=0x9c;		  //������T1�����ֵ
	TH1=TL1;
	ET1=1;			  //��T1�ж�
		
	TR0=1;				//�򿪶�ʱ��T0
	TR1=1;			  //�򿪼�����T1		
while(1);	
}