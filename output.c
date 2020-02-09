#include<stdio.h>
extern int(*Q)[10];
extern int gs,bs;//第几关


//输出地图
int output(void)
{
	int I, J;
	printf("第%d关      第%d步\n",gs,bs);
	for (I = 0; I<10; I++)
	{
		for (J = 0; J < 10; J++)
		{
			switch (*(*(Q+I)+J))
			{
			case 0:printf("  "); break;
			case 1:printf("■"); break;
			case 2:printf("○"); break;
			case 3:printf("●"); break;
			case 4:printf("★"); break;
			}
		}
		printf("\n"); 
	}
	printf("上一关(L)  菜单(C)\n");
	return 0;
}
