#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h>
extern int gs,bs,gsm,bsm,n;
extern int wj;

#define N 10
struct user
{
	char name[20];
	int num_gs;
	int num_gsm;
	int num_bs;
	int num_bsm;
}users[N];
void gotoxy(int x, int y) //定位到第y行的第x列
{
	int xx=0x0b;
	HANDLE hOutput;
	COORD loc;
	loc.X = x;
	loc.Y=y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
	return;
}

char meun()
{
	FILE *fp;
	fp = fopen("go_on.txt","r");
	fscanf(fp,"%d\t%d",&gs,&n);
	fclose(fp);
	
	
	int wj=0;
	char af;
    int i,a[5],ad=1,ab;
    for(i=0;i<5;i++)
        printf(" ");
    for(i=0;i<5;i++)
    {
        gotoxy(2,i);
        switch(i)
        {
            case 0:printf("开始");break;
            case 1:printf("继续");break;
            case 2:printf("排行榜");break;
            case 3:printf("帮助");break;
            case 4:printf("退出\n");break;
        }
    }
    gotoxy(0,5);
    printf("向上:W  向下:S \n确定:D ");
    gotoxy(0,ad-1);
    printf("●");
    af=getch();
    if(af=='d'||af=='D')
        ab=ad;
    while(af!='d'&&af!='D')
    {
        gotoxy(0,ad-1);
        printf(" ");
        if(af=='w'||af=='W')
        {
            ad=ad-1;
            if(ad==0)
                ad=5;
        }
        else if(af=='s'||af=='S')
        {
            ad=ad+1;
            if(ad==6)
                ad=1;
        }
        for(i=0;i<5;i++)
            printf(" ");
        for(i=0;i<5;i++)
        {
            gotoxy(2,i);
            switch(i)
            {
                case 0:printf("开始");break;
                case 1:printf("继续");break;
                case 2:printf("排行榜");break;
                case 3:printf("帮助");break;
                case 4:printf("退出\n");break;
            }
        }
        gotoxy(0,5);
        printf("向上:W  向下:S \n确定:D ");
        gotoxy(0,ad-1);
        printf("●");
        af=getch();
        if(af=='d'||af=='D')
        {
            ab=ad;
            break;
        }
    }

	system("cls");
	if (ab ==1)
	{
		gs = 0;
		map();//引用函数产生第一张地图
		output();//输出第一张地图
		circle();
	}
	
	else if (ab ==2)
	{
		FILE *fp;
		fp = fopen("go_on.txt","r");
		fscanf(fp,"%d\t%d",&gs,&n);
		fclose(fp);
		if(gs==0) ++gs;
		--gs;
		map();//引用函数产生第一张地图
		output();//输出第一张地图
		circle();
	}
	else if(ab ==3)
	{
		wj=0;
		FILE *fp1;
		fp1 = fopen("user.txt","r");
		for(wj=0;wj<n;wj++)
		fscanf(fp1,"%s\t%d\t%d\t%d\t%d\n",&users[wj].name,&users[wj].num_gs,&users[wj].num_gsm,&users[wj].num_bs,&users[wj].num_bsm);
		fclose(fp1);
		int i1,j1;
		int gsl,gsml,bsl,bsml;
		char name[20];
		for(i1=0;i1<N;i1++)
		for(j1=i1;j1<n;j1++)
		{
			if(users[j1].num_gsm>users[i1].num_gsm)
			{
				struct user users11;
				users11=users[j1];
				users[j1]=users[i1];
				users[i1]=users11;	
				
			}
		}
		printf("名次\t玩家\t关数\t步数\n");
		for(i1=0;i1<N;i1++)
		printf(" %d.\t%s\t %d\t %d\n",i1+1,users[i1].name,users[i1].num_gsm,users[i1].num_bs);
		printf("菜单(C)\n");
		if(n>10)
		{
			n=10;
			FILE *fp;
			fp = fopen("user.txt","w");
			for(wj=0;wj<N;wj++)
			fprintf(fp,"%s\t%d\t%d\t%d\t%d\n",users[wj].name,users[wj].num_gs,users[wj].num_gsm,users[wj].num_bs,users[wj].num_bsm);
			fclose(fp);
		}
		ab=getch();
		while(!(ab=='C'||ab=='c'))
		{
			system("cls");
			printf("名次\t玩家\t关数\t步数\n");
			for(i1=0;i1<N;i1++)
			printf(" %d.\t%s\t %d\t %d\n",i1+1,users[i1].name,users[i1].num_gsm,users[i1].num_bs);
			printf("菜单(C)\n");
			ab=getch();
		}
		system("cls");
		meun();
	}
	else if(ab ==4)
	{
		printf("*******帮助*******\n\n\  W\nA S D 移动  B 撤回\n\nL 上一关  N 下一关\n\nR 重玩    C 菜单\n\n菜单(C)\n");
		ab=getch();
		while(!(ab=='C'||ab=='c'))
		{
			system("cls");
			printf("*********帮助********\n   \n 菜单(C)\n");
			ab=getch();
		}
		system("cls");
		meun();
	}
	else if(ab ==5)
	{
		system("cls");
		//char name[15];
		printf("请留尊姓大名：\n");
		scanf("%s",users[wj].name);
		users[wj].num_gs=gs;
		users[wj].num_gsm=gsm;
		users[wj].num_bs=bsm;
		FILE *fp;
		fp = fopen("go_on.txt","w");
		fprintf(fp,"%d\t%d",gs,n+1);
		fclose(fp);
		FILE *fp1;
		fp1 = fopen("user.txt","a+");
		fprintf(fp1,"%s\t%d\t%d\t%d\t%d\n",users[wj].name,users[wj].num_gs,users[wj].num_gsm,users[wj].num_bs,users[wj].num_bsm);
		fclose(fp1);
		exit(0);
	}
	return ab;
}
