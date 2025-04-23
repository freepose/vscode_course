#include <stdio.h>
#include "idiom.h"
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

void BeginGuessGame(IDIOM *idioms, RANKING *userLocPtr, int idiomLen)
{
	char yourIdiom[20]; // 用户输入的成语
	int id;
	char ch;
	int rightflag = 0; // 回答是否正确的标志
	while (1)
	{
		system("cls");
		GuessBeginMenu(); // 猜成语界面

		srand(time(0));			// 产生随机数
		id = rand() % idiomLen; // 随机抽取一个数。
		printf("---------------------您抽到的成语内容是--------------------------\n");
		printf("%s\n", idioms[id].illustation);

		printf("本题是否要继续答y/n:");
		scanf("\n%c", &ch);
		if (ch == 'n') // 不继续玩，返回游戏主界面
		{
			GotoMainMenu(userLocPtr->score[1], userLocPtr->score[2]);
			return;
		}
		printf("输入您猜的成语：");
		scanf("%s", yourIdiom);

		if (strcmp(yourIdiom, idioms[id].idiom) == 0) // 成语答对，计分，更新用户分数
		{
			rightflag = 1;
		}
		else
			rightflag = 0;
		getScore(userLocPtr, idioms[id].idiom, rightflag); // 评分
	}
}
void getScore(RANKING *userLocPtr, char *rightAnswer, int rightflag) // 根据用户回答结果评分，更新排名成绩
{
	char ch;
	if (rightflag == 1) // 成语答对，计分，更新用户分数
	{
		userLocPtr->score[1]++;
		printf("\n非常棒!回答对了，加5分！\n");
		userLocPtr->score[0] = userLocPtr->score[0] + SCORE;
		Sleep(1000);
	}
	else // 成语答错
	{
		userLocPtr->score[2]++;
		printf("回答错误\n正确答案是：%s \n是否继续y/n:", rightAnswer);
		scanf("\n%c", &ch);
		if (ch == 'n') // 不继续玩，返回游戏主界面
		{
			GotoMainMenu(userLocPtr->score[1], userLocPtr->score[2]);
			return;
		}
	}
}
void GotoMainMenu(int rightNumber, int wrongNumber) // 回答否的操作
{
	printf("您共答对%d题，答错%d题\n", rightNumber, wrongNumber);
	Sleep(1000);
	system("cls");
	OperateGameMenu(); // 返回游戏操作主菜单
}
int GetIdiomData(IDIOM *idiomPtr) // 读取成语文件
{
	FILE *fp;
	char str[500]; // 文件读取时存进的临时数组。
	int location = -1;
	char *locPtr = NULL;
	int idiomLen = 0;

	if ((fp = fopen("idiom.txt", "r")) == NULL)
	{
		FileException(); // 文件读取失败处理函数
		return 0;
	}

	while (!feof(fp))
	{
		fgets(str, 500, fp);
		locPtr = strchr(str, ':'); // 查找字符冒号，找到返回指针指向该位置，找不到返回NULL
		if (locPtr != NULL)		   // 找到冒号处理
		{
			location = locPtr - str;								// 指针相减，得到冒号位置
			memset(idiomPtr->idiom, '\0', sizeof(idiomPtr->idiom)); // 字符串初值置0
			memset(idiomPtr->illustation, '\0', sizeof(idiomPtr->illustation));
			strncpy(idiomPtr->idiom, str, location);		   // 从某个字符串地址复制n个字符到目的地址
			strcpy(idiomPtr->illustation, str + location + 1); // 复制字符串
			idiomLen++;
			// printf("%d,%s,&s\n", idiomLen, idiomPtr->idiom, idiomPtr->illustation);
			idiomPtr++;
		}
		else
		{
			FileException(); // 找不到，返回上一级菜单，结束
			return 0;
		}
	}
	fclose(fp); // 读完文件要关闭
	return idiomLen;
}
void BeginFillGame(IDIOM *idioms, RANKING *userLocPtr, int idiomLen) // 补充成语游戏
{
	char character1[4], character2[4]; // 两个汉字
	char idiomstr[20];				   // 存随机抽取的成语
	char characters[100][4];		   // 成语每个汉字存在二维数组中
	int loc[2];						   // 存放2个造空汉字所在数组下标
	int idiom_id;					   // 成语随机号
	int characterNum = 0;			   // 汉字数量
	int rightflag = 0;				   // 是否正确的标志
	char ch;
	while (1)
	{
		system("cls");
		FillIdiomMenu();								 // 补成语界面
		srand(time(0));									 // 产生随机数
		idiom_id = rand() % idiomLen;					 // 随机抽取一个成语位置
		strcpy(idiomstr, idioms[idiom_id].idiom);		 // 成语内容复制到idiomstr中保存
		SplitIdiom(idiomstr, characters, &characterNum); // 分割成语,一个个存入相应字符串
		CreateBlanks(characters, characterNum, loc);	 // 成语造空
		printf("%s\n", idioms[idiom_id].illustation);
		printf("本题是否要继续答y/n:");
		scanf("\n%c", &ch);
		if (ch == 'n') // 不继续玩，返回游戏主界面
		{
			GotoMainMenu(userLocPtr->score[1], userLocPtr->score[2]);
			return;
		}
		printf("请补充空格内的汉字，空格隔开：");
		scanf("%s %s", character1, character2);
		if (strcmp(character1, characters[loc[0]]) == 0 &&
			strcmp(character2, characters[loc[1]]) == 0) // 2个汉字回答都正确
		{
			rightflag = 1;
		}
		else
			rightflag = 0;
		getScore(userLocPtr, idiomstr, rightflag); // 进入评分模块
	}
}
void SplitIdiom(char *idiomstr, char characters[][4], int *characterNum) // 分割成语
{
	int i;
	i = 0;
	*characterNum = 0;
	while (idiomstr[i]) // 遍历成语
	{
		characters[*characterNum][0] = idiomstr[i];		// 1个汉字占2字节，读取第1个字节
		characters[*characterNum][1] = idiomstr[i + 1]; // 读取第2个字节
		characters[*characterNum][2] = 0;				// 加入结束标志
		// printf("%d:%s\n", *characterNum, characters[*characterNum]);
		i = i + 2;
		(*characterNum)++; // 统计成语中汉字数量，有些成语不止4个汉字
	}
}
void CreateBlanks(char characters[][4], int characterNum, int loc[]) // 成语造空
{
	int character_id1, character_id2; // 汉字随机号
	int i;
	int j = 0;
	do
	{
		srand(time(0)); // 产生随机数
		character_id1 = rand() % characterNum;
		character_id2 = rand() % characterNum;
	} while (character_id1 >= character_id2); // 保证第一个位置下标小于第二个的
	printf("                       ");
	for (i = 0; i < characterNum; i++)
	{
		if (i == character_id1 || i == character_id2)
		{
			printf(" (%d)__ ", j + 1); // 找到空位置，设计填空样式
			loc[j++] = i;			   // 空位置所在下标存入数组，以便核对答案
		}
		else
		{
			printf("%s ", characters[i]); // 非空位置，原样输出汉字
		}
	}
	printf("\n");
}
