#include<reg51.h>
sbit P1_0=P1^0;
void main(){
	TMOD=0x00;			//���ù�����ʽ
	TR0=1;					//������ʱ��T0
	while(1){
		TH0=0xf0;			//�����ֵ
		TL0=0x0c;
		while(!TF0);	//��ѯTF0��λ
		P1_0=!P1_0;		//��ʱ����ȡ��
		TF0=0;				//���TF0��0	
	}
}
/*
#include<reg51.h>
sbit P1_0=P1^0;
turn()interrupt 1	//1���жϿ���T0
{
		P1_0=!P1_0;		//��ʱ����ȡ��	
		TH0=0xfe;			//�����ֵ
		TL0=0x0c;	
}
void main(){
		TMOD=0x01;		//���ù�����ʽ
		EA=1;					//�����ж�
		ET0=1;				//��T0�ж�		
		TH0=0xfe;			//�����ֵ
		TL0=0x0c;
 	  TR0=1;				//�򿪶�ʱ��T0
while(1);	
}*/