#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<stdio.h>
extern int xr, yr;//С��λ�� 
extern int xx, yx;//����λ�� 
extern int gs,bs,n; //���������� 
extern int(*Q)[10];//��ͼָ�� 
extern int l, i, q, p, w[7], e[7];


int circle(void)
{
	int judge(int(*p1)[10]);
	int output(void);
	int xs, ys;//С���˶�ǰ��һ��λ��
	
	
	//ѭ��
	while (judge(Q))
	{
		int ab,ac;
		char a;//С���˶���������
		xs = xr; ys = yr;
		a = getch();
		
		
		//������һ���ж� 
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
		
		
		
		//С�������ƶ��ж� 
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
		
		
		//С�������ƶ��ж� 
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
		
		
		//С�������ƶ��ж� 
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
		
		
		//С�������ƶ��ж� 
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
		
		
		
		/*else if (a == 'N' || a == 'n')//��һ���ж� 
		{
			map();
		}*/
		
		
		
		
		//���ز˵��ж� 
		else if(a == 'C'||a=='c') 
		{
			system("cls");
			FILE *fp1;
			fp1 = fopen("go_on.txt","w");
			fprintf(fp1,"%d\t%d",gs,n);
			fclose(fp1);
			meun();break;
		}
		
		
		//���������ж� 
		else if (a == 'R' || a == 'r')
		{
			--gs;
			map();
			a = 1;
		}
		
		
		//������һ���ж� 
		else if (a == 'L' || a == 'l')
		{
			if(gs>1)
			{
				gs=gs-2;
				map();
			}
		}
		
		
		//С����λ�ö�Ϊ4 
		 *(*(Q + xr) + yr) = 4;
		 
		 //�ж�����ָ��λ���Ƿ�Ϊ���ӻ���С�� 
		for (l = 0; l < i; l++)
		{
			if (*(*(Q + w[l]) + e[l]) != 4 && *(*(Q + w[l]) + e[l]) != 3)
				*(*(Q + w[l]) + e[l]) = 2;
		}
		
		
		//���������µ�ͼ
		system("cls");
		output();
		printf("\n");
	}
	return 0;
}
