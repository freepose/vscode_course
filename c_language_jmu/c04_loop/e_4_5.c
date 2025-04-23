#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	int option;
	do
	{
		printf("****************欢迎进入党建学习系统***************\n");
		printf("*               1:我要读文章                      *\n");
		printf("*               2:视听学习                        *\n");
		printf("*               3:每日答题                        *\n");
		printf("*               4:双人对战                        *\n");
		printf("*               0:退出程序                        *\n");
		printf("***************************************************\n");
		printf("请输入您的选择:");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("您的选择是：我要读文章\n");
			break;
		case 2:
			printf("您的选择是：视听学习\n");
			break;
		case 3:
			printf("您的选择是：每日答题\n");
			break;
		case 4:
			printf("您的选择是：双人对战\n");
			break;
		case 0:
			printf("您的选择是：退出游戏");
			exit(0); // 退出游戏,需要包含头文件stdlib.h
		default:
			printf("输入有误，请重输！\n");
			Sleep(500);	   // 等待500ms程序再继续执行
			system("cls"); // 清屏函数
		}
	} while (option < 0 || option > 4);
	return 0;
}
