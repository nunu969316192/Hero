#include<conio.h>
#include<graphics.h>
#include<windows.h>
#include<iostream>
#define width 640//������
#define height 480//����
using namespace std;

IMAGE bg,Rhero[8],Rheroym[8],Lhero[8],Lheroym[8];
IMAGE attack_1[8],attackym_1[8];//����1
IMAGE attack_2[13],attack_2[13];//����2


void init()
{
		/************��ʼ��************/
		initgraph(width,height);
		char Rbuff[512],Rbuffym[512];//������ұ��ƶ���ͼƬ
		char Lbuff[512],Lbuffym[512];//���������ƶ���ͼƬ
		char attack_1_buff[512],attack_1_buffym[512];//�����attck1��ͼƬ��������
		char attack_2_buff[512],attack_2_buffym[512];//�����attack2��ͼƬ��������
		int i=0;

		//���ر���
		loadimage(&bg,_T("bg\\bg_3.jpg"),width,height,true);



		/*******************��ʼ��walk**************/
		//����ͼƬ
		for(i=0;i<=6;i++)
		{
			memset(Rbuff,0,512);
			memset(Lbuff,0,512);
			//����
			sprintf(Rbuff,_T("walk\\IMG0000%d.bmp"),i);
			loadimage(&Rhero[i],Rbuff,0,0,true);
			//����
			sprintf(Lbuff,_T("walk\\%d.bmp"),i);
			loadimage(&Lhero[i],Lbuff,0,0,true);


		}
		//��������ͼ
		for(i=0;i<=6;i++)
		{
			memset(Rbuffym,0,512);
			memset(Lbuffym,0,512);
			sprintf(Rbuffym,_T("walk\\IMG0000%d_ym.bmp"),i);
			loadimage(&Rheroym[i],Rbuffym,0,0,true);
			sprintf(Lbuffym,_T("walk\\%d_ym.bmp"),i);
			loadimage(&Lheroym[i],Lbuffym,0,0,true);
		}


		/**************************����attack��ʼ��*****************/
		//����ͼƬ

		/*********attack1******/
		for(i=0;i<=6;i++)
		{
			memset(attack_1_buff,0,512);
			sprintf(attack_1_buff,_T("attack1\\IMG0000%d.bmp"),i);
			loadimage(&attack[i],attack_1_buff,0,0,true);
		}

		//��������ͼ
		for(i=0;i<=6;i++)
		{
			memset(attack_buffym,0,512);
			sprintf(attack_buffym,_T("attack1\\IMG0000%d_ym.bmp"),i);
			loadimage(&attackym[i],attack_buffym,0,0,true);
		}
		
		/*************attack2***************/
		for(i=0;i<=13;i++)
		{
			memset(attack1_buff,0,512);
			sprintf(attack1_buff,_T("attack2\\IMG0000%d.bmp"),i);
			loadimage(&attack[i],attack1_buff,0,0,true);
		}
		//��������ͼ
		for(i=0;i<=13;i++)
		{
			memset(attack_buffym,0,512);
			sprintf(attack_buffym,_T("attack2\\IMG0000%d_ym.bmp"),i);
			loadimage(&attackym[i],attack_buffym,0,0,true);
		}
}

























void show()
{
		int x=200,y=300;//��ʼ��λ��
		int count=0;
		char ch;
		int dire;//�����ж�
		while(ch != 27)
		{
			ch = getch();
			switch(ch)
			{
			case 'a'://����
				for(count=0;count<=6;count++)
				{
					putimage(0,0,&bg);
					putimage(x,y,&Lheroym[count],SRCAND);
					putimage(x,y,&Lhero[count],SRCPAINT);
					x-=10;
					Sleep(10);
					dire=0;//0Ϊ����
				}
				break;
			case 'd'://����
				for(count=0;count<=6;count++)
				{
					putimage(0,0,&bg);
					putimage(x,y,&Rheroym[count],SRCAND);
					putimage(x,y,&Rhero[count],SRCPAINT);
					x+=10;
					Sleep(10);
					dire=1;//1Ϊ����
				}
				break;
			case 'w'://����
				for(count=0;count<=6;count++)
				{	
					putimage(0,0,&bg);
					if(dire==0)
					{
						putimage(x,y,&Lheroym[count],SRCAND);
						putimage(x,y,&Lhero[count],SRCPAINT);
					}
					else
					{
						putimage(x,y,&Rheroym[count],SRCAND);
						putimage(x,y,&Rhero[count],SRCPAINT);
					}
					y-=10;
					Sleep(10);
				}
				break;
			case 's'://����
				for(count=0;count<=6;count++)
				{	
					putimage(0,0,&bg);
					if(dire==0)
					{
						putimage(x,y,&Lheroym[count],SRCAND);
						putimage(x,y,&Lhero[count],SRCPAINT);
					}
					else
					{
						putimage(x,y,&Rheroym[count],SRCAND);
						putimage(x,y,&Rhero[count],SRCPAINT);
					}
					y+=10;
					Sleep(10);
				}
				break;
			case 'j'://����
				for(count=0;count<=13;count++)
				{
						putimage(0,0,&bg);
						putimage(x,y,&attackym[count],SRCAND);
						putimage(x,y,&attack[count],SRCPAINT);
						x-=10;
						Sleep(10);
				}
				break;

			}
		};
}









int main()
{			

	init();
	show();
	return 0;
}