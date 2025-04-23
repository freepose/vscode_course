// IdiomMain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <stdio.h>
#include <stdlib.h>
#include "idiom.h"
#include <windows.h>
#include <time.h>

IDIOM *idioms;		 // 成语结构体指针
RANKING *ranks;		 // 排名结构体指针
int idiomLen = 0;	 // 成语数量
int rankLen = 0;	 // 排名数量
char *user;			 // 登录用户
RANKING *userLocPtr; // 当前用户在排名结构体指针

int main()
{

	/*打开数据文件*/
	idioms = (IDIOM *)calloc(LEN, sizeof(IDIOM)); // 动态申请LEN个结构体空间?
	idiomLen = GetIdiomData(idioms);			  // 读取成语文件，成语数量保存到idomLen
	ranks = (RANKING *)calloc(LEN, sizeof(RANKING));
	rankLen = GetRankData(ranks); // 打开排名文件
	GotoSystemMenu();
	user = (char *)malloc(30);
	printf("请输入游戏用户名：");
	scanf("%s", user);
	/*查找用户是否存在，存在则定位到该用户位置，不存在则定位到最后一条记录*/
	userLocPtr = SetUserInfo(ranks, &rankLen, user);
	OperateGameMenu();
	return 0;
}
void OperateGameMenu() // 游戏操作界面
{
	char option;
	int i;
	do
	{
		system("cls");
		MainMenu(user); // 游戏菜单
		printf("请输入您的选择：");
		scanf(" %c", &option);
		switch (option)
		{
		case '1':										  // 选择猜成语模块
			BeginGuessGame(idioms, userLocPtr, idiomLen); // 猜成语游戏
			break;
		case '2':										 // 选择补成语模块
			BeginFillGame(idioms, userLocPtr, idiomLen); // 补充成语游戏
			break;
		case '3':						  // 游戏排名展示模块
			SortRanking(ranks, rankLen);  // 排序
			PrintRanking(ranks, rankLen); // 展示
			Sleep(1000);				  // 暂停1000ms
			char ch;
			printf("\n输入任意键返回：");
			getchar();	  // 输入字符
			getchar();	  // 吸收换行符
			option = '5'; // 可继续输入做选择
			break;
		case '4':							// 结束，退出程序
			WriteToRanking(ranks, rankLen); // 保存排名文件
			free(idioms);					// 释放动态内存
			free(ranks);					// 释放内存
			printf("\n谢谢您的参与！\n");
			Sleep(500);
			exit(0);
		default:
			printf("输入错误，只能输入1,2,3,4，请重输！\n");
			Sleep(500);
		}
	} while (!(option >= '1' && option <= '4'));
}
