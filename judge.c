#include<stdio.h>
#include<conio.h>
int map(void);
int output(void);
extern int gs,gsm,bs,bsm;//关数，最大关数 
extern int  i,l, w[7], e[7];



//判断是否进入下一关 
int judge(int (*p1)[10])
{
	
	//判断是否箱子是否都到指定位置 
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
		printf("下一关(N)  重玩(R)：\n");
		
		
		//输入正确的字符 
		char b;
		b = getch();
		
		
		
		// 重玩 
		if (b == 'R' || b == 'r')
		{
			--gs;
			map();
			a = 1;
		}
		
		//下一关 
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
				printf("\n\n 恭喜您通关\n\n菜单(C)\n");
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
		
		//菜单 
		else if(b == 'C'||b=='c') 
		{
			system("cls");
			meun();
		}
		
		//上一关 
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
