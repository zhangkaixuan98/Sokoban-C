#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<stdio.h>
extern int xr, yr;//小人位置 
extern int xx, yx;//箱子位置 
extern int gs,bs,n; //关数，步数 
extern int(*Q)[10];//地图指针 
extern int l, i, q, p, w[7], e[7];


int circle(void)
{
	int judge(int(*p1)[10]);
	int output(void);
	int xs, ys;//小人运动前上一个位置
	
	
	//循环
	while (judge(Q))
	{
		int ab,ac;
		char a;//小人运动方向输入
		xs = xr; ys = yr;
		a = getch();
		
		
		//返回上一步判断 
		if(a=='b'||a=='B')
		{
			if(ac==1)
			switch(ab)
			{
				case 1:*(*(Q + xx) + yx) =0;xr=xr+1;xx=xr-1;yx=yx;*(*(Q + xx) + yx) =3;ac=0;--bs;break;
				case 2:*(*(Q + xx) + yx) =0;xr=xr-1;xx=xr+1;yx=yx;*(*(Q + xx) + yx) =3;ac=0;--bs;break;
				case 3:*(*(Q + xx) + yx) =0;yr=yr-1;yx=yr+1;xx=xx;*(*(Q + xx) + yx) =3;ac=0;--bs;break;
				case 4:*(*(Q + xx) + yx) =0;yr=yr+1;yx=yr-1;xx=xx;*(*(Q + xx) + yx) =3;ac=0;--bs;break;
			}
		}
		ac=0;
		
		
		
		//小人向上移动判断 
		if (a == 'w' || a == 'W')
		{
			switch (*(*(Q + xr - 1) + yr))
			{
			case 0:/*xs = xr; ys = yr;*/ xr = xr - 1;bs++; break;
			case 1:xr = xr; break;
			case 2:xr = xr - 1; bs++;break;
			case 3:if (*(*(Q + xr - 2) + yr) != 1 && *(*(Q + xr - 2) + yr) != 3)
				{
					ab=1;
					   xx = xr - 2; yx = yr; xr = xr - 1; *(*(Q + xx) + yx) = 3;bs++;ac=1;
				}break;
			}
			*(*(Q + xs) + ys) = 0;
		}
		
		
		//小人向下移动判断 
		else if (a == 's' || a == 'S')
		{
			switch (*(*(Q + xr + 1) + yr))
			{
			case 0:xs = xr; ys = yr; xr = xr + 1;bs++; break;
			case 1:xr = xr; break;
			case 2:xr = xr + 1; bs++;break;
			case 3:if (*(*(Q + xr + 2) + yr) != 1 && *(*(Q + xr + 2) + yr) != 3)
				{
						ab=2;
					   xx = xr + 2; yx = yr; xr = xr + 1; *(*(Q + xx) + yx) = 3;bs++;ac=1;
				} break;
			}
			*(*(Q + xs) + ys) = 0;
		}
		
		
		//小人向右移动判断 
		else if (a == 'd' || a == 'D')
		{
			switch (*(*(Q + xr) + yr + 1))
			{
			case 0:ys = yr; xs = xr; yr = yr + 1; bs++;break;
			case 1:yr = yr; break;
			case 2:yr = yr + 1; bs++;break;
			case 3:if (*(*(Q + xr) + yr + 2) != 1 && *(*(Q + xr) + yr + 2) != 3)
				{
						ab=3;
					   yx = yr + 2; xx = xr; yr = yr + 1; *(*(Q + xx) + yx) = 3;bs++;ac=1;
				} break;
			}
			*(*(Q + xs) + ys) = 0;
		}
		
		
		//小人向左移动判断 
		else if (a == 'a' || a == 'A')
		{
			switch (*(*(Q + xr) + yr - 1))
			{
			case 0:ys = yr; xs = xr; yr = yr - 1;bs++; break;
			case 1:yr = yr; break;
			case 2:yr = yr - 1;bs++; break;
			case 3:if (*(*(Q + xr) + yr - 2) != 1 && *(*(Q + xr) + yr - 2) != 3)
				{
						ab=4;
					   yx = yr - 2; xx = xr; yr = yr - 1; *(*(Q + xx) + yx) = 3;bs++;ac=1;
				}break;
			}
			*(*(Q + xs) + ys) = 0;
		}
		
		
		
		/*else if (a == 'N' || a == 'n')//下一关判断 
		{
			map();
		}*/
		
		
		
		
		//返回菜单判断 
		else if(a == 'C'||a=='c') 
		{
			system("cls");
			FILE *fp1;
			fp1 = fopen("go_on.txt","w");
			fprintf(fp1,"%d\t%d",gs,n);
			fclose(fp1);
			meun();break;
		}
		
		
		//返回重玩判断 
		else if (a == 'R' || a == 'r')
		{
			--gs;
			map();
			a = 1;
		}
		
		
		//返回上一关判断 
		else if (a == 'L' || a == 'l')
		{
			if(gs>1)
			{
				gs=gs-2;
				map();
			}
		}
		
		
		//小人新位置定为4 
		 *(*(Q + xr) + yr) = 4;
		 
		 //判断箱子指定位置是否为箱子或者小人 
		for (l = 0; l < i; l++)
		{
			if (*(*(Q + w[l]) + e[l]) != 4 && *(*(Q + w[l]) + e[l]) != 3)
				*(*(Q + w[l]) + e[l]) = 2;
		}
		
		
		//清屏产生新地图
		system("cls");
		output();
		printf("\n");
	}
	return 0;
}
