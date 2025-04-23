#include <stdio.h>
#include <stdlib.h>

void menu() // 主菜单
{
	printf("****************欢迎进入党建学习系统***************\n");
	printf("*               1:我要读文章                      *\n");
	printf("*               2:视听学习                        *\n");
	printf("*               3:每日答题                        *\n");
	printf("*               4:双人对战                        *\n");
	printf("*               0:退出程序                        *\n");
	printf("***************************************************\n");
}
void read()
{
	printf("您的选择是：我要读文章\n");
}
void audiostudy()
{
	printf("您的选择是：视听学习\n");
}
void Dailyproblemsolving()
{
	printf("您的选择是：每日答题\n");
}
void doubleagainst()
{
	printf("您的选择是：双人对战\n");
}
void exitsystem()
{
	printf("您的选择是：退出程序\n");
}
void error()
{
	printf("输入有误，输入数字只能是0,1,2,3,4！\n");
}

int main()
{
	int option;
	menu();
	while (1)
	{
		printf("请输入您的选择:");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			read();
			break;
		case 2:
			audiostudy();
			break;
		case 3:
			Dailyproblemsolving();
			break;
		case 4:
			doubleagainst();
			break;
		case 0:
			exitsystem();
			exit(0); // exit(0)是结束整个程序
		default:
			error();
		}
	}
	return 0;
}
