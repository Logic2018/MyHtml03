#include<reg51.h>
sbit P1_0=P1^0;
void main(){
	TMOD=0x02;			//���ù�����ʽ
	TH0=0x06;			  //�����ֵ
	TL0=TH0;
	while(1){
		TR0=1;				//������ʱ��T0
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
}
void main(){
		TMOD=0x02;		//���ù�����ʽ
		EA=1;					//�����ж�
		ET0=1;				//��T0�ж�		
		TH0=0x06;			//�����ֵ
		TL0=TH0;
 	  TR0=1;				//�򿪶�ʱ��T0
    while(1);	
}*/