#include<stdio.h>
#include<conio.h>
int map(void);
int output(void);
extern int gs,gsm,bs,bsm;//������������ 
extern int  i,l, w[7], e[7];



//�ж��Ƿ������һ�� 
int judge(int (*p1)[10])
{
	
	//�ж��Ƿ������Ƿ񶼵�ָ��λ�� 
	int a = 0,d=0;
	for (l = 0; l<i; l++)
	{
		if (*(*(p1+w[l])+e[l]) == 3)  d++;
		a = 1;
	}
	if (d == i) a = 0;
	
	
	
	// 
	while (a == 0)
	{
		printf("��һ��(N)  ����(R)��\n");
		
		
		//������ȷ���ַ� 
		char b;
		b = getch();
		
		
		
		// ���� 
		if (b == 'R' || b == 'r')
		{
			--gs;
			map();
			a = 1;
		}
		
		//��һ�� 
		else if (b == 'N' || b == 'n')
		{
			if((gs-1)>=gsm) 
			{
				gsm=gs;
				bsm=bs;
			}
			if(gs==5)
			{
				system("cls");
				printf("\n\n ��ϲ��ͨ��\n\n�˵�(C)\n");
				a=0;
				b = getch();
				while (!(b == 'C'||b=='c'))
				{	
					b = getch();
				}
				system("cls");
				meun();
				break;
			}
			
			else 
			{
				map();
				a=1;	
			}
		}
		
		//�˵� 
		else if(b == 'C'||b=='c') 
		{
			system("cls");
			meun();
		}
		
		//��һ�� 
		else if (b == 'L' || b == 'l')
		{
			
			gs=gs-1;
			map();
			a=1;
		}
		system("cls");
		output();
	}
	return a;
}
