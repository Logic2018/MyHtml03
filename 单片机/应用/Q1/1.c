#include<reg51.h>
char led[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf};
bit dir=0,run=0;
unsigned int i=0;
unsigned int t=1000;		 		  //Ĭ��1ms*1000
void delay(unsigned int t){	  //��ʱ1ms*t
	TMOD=0x01;	      //T0�ķ�ʽ1
	while(1){
		TH0=0xfc;				//��ʱ1ms
		TL0=0x18;
		TR0=1;				  //�򿪶�ʱ��
		while(!TF0);		//��ѯ�Ƿ��ʱ����
		if(++i%t==0)		//	#1	
			break;
		TF0=0;
	}
}
key()interrupt 0{
	switch(P0&0x0f){			//���ؿ���
		case 0x0e:run=1;dir=0;break;//���µ���
		case 0x0d:run=1;dir=1;break;//���ϵ���
		case 0x0b:t=t/2;break;
		case 0x07:dir=0;run=0;break;
	}
}
void main(){
	char i;
	EA=1;            //�����ж�
	EX0=1;           //��INT0�ж�
	IT0=1;					 //INT0���ñ��ش�����ʽ
	
				
	while(1){
		P2=0x2a;				//�ʵ�ʵ�ֽ�����˸
		if(run){				//��ˮ��	
			if(dir) 
				for( i=0;i<=5;i++){	//���µ���
					P2=led[i];
					delay(t);
				}
			else	  
				for(i=5;i>=0;i--){  //���ϵ���
					P2=led[i];
					delay(t);
			}
		}		
		P2=0x15;				//�ʵ�ʵ�ֽ�����˸
	}
}