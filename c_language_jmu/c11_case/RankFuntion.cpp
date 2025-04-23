#include <stdio.h>
#include "idiom.h"
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

int GetRankData(RANKING *ranks)
{

	int i = 0;
	FILE *fp;
	if ((fp = fopen("ranking.txt", "r")) == NULL)
	{
		FileException();
		return 0;
	}

	while (!feof(fp))
	{
		fscanf(fp, "%d%s%d%s", &ranks[i].ranking, ranks[i].user, &ranks[i].score[0], ranks[i].datetime);
		// printf("%d,%s,%d,%s\n", ranks[i].ranking, ranks[i].user, ranks[i].score[0], ranks[i].datetime);
		i++;
	}
	fclose(fp);
	return i;
}

int ExistUser(char *user, RANKING *ranks, int *rankLen) // 查找用户是否存在
{
	RANKING *ptr;

	for (ptr = ranks; ptr < ranks + *rankLen; ptr++) // 整个结构体数组查找
	{

		if (strcmp(ptr->user, user) == 0) // 找到用户
		{
			return ptr - ranks; // 找到则返回位置下标
		}
	}
	return -1; // 找不到返回-1
}

RANKING *SetUserInfo(RANKING *ranks, int *rankLen, char *user) // 设置用户的排名初始信息
{
	RANKING *userLocPtr;
	userLocPtr = (RANKING *)malloc(sizeof(RANKING));
	int loc;
	loc = ExistUser(user, ranks, rankLen); // 查找用户是否存在函数
	if (loc == -1)						   // 用户不存在，则增加新用户
	{
		int i;
		userLocPtr = ranks + *rankLen;	// 指针定为到最后一条记录，增加新用户
		strcpy(userLocPtr->user, user); // 设计用户信息
		*rankLen = *rankLen + 1;
		userLocPtr->ranking = *rankLen; // 排名
		for (i = 0; i < 3; i++)
			userLocPtr->score[i] = 0; // 得分清零
		ranks[*rankLen] = *userLocPtr;
	}
	else // 用户存在
	{
		userLocPtr = ranks + loc; // 定位到已存在的记录位置
	}
	time_t timep;
	time(&timep);																// 获取系统时间
	strftime(userLocPtr->datetime, 30, "%Y-%m-%d/%H:%M:%S", localtime(&timep)); // 设置游戏时间
	// printf("1:loc=%d,len=%d,id=%d,user=%s,s=%d,date=%s\n",loc,rankLen, userLocPtr->ranking, userLocPtr->user, userLocPtr->score[0], userLocPtr->datetime);
	return userLocPtr;
}
void SortRanking(RANKING *ranks, int rankLen) // 成绩排序
{
	int i = 0;
	int j = 0;
	RANKING temp;
	int maxIndex;

	for (i = 0; i < rankLen; i++) // 选择法降序排序
	{
		maxIndex = i;
		for (j = i + 1; j < rankLen; j++)
		{
			if (ranks[j].score[0] > ranks[maxIndex].score[0]) // 找最高成绩
			{
				maxIndex = j;
			}
		}
		temp = ranks[i];
		ranks[i] = ranks[maxIndex];
		ranks[maxIndex] = temp;
		ranks[i].ranking = i + 1; // 修改排名序号
								  // printf("id=%d,user=%s,s=%d,date=%s\n", ranks[i].ranking, ranks[i].user, ranks[i].score[0], ranks[i].datetime);//测试是否正确排序
	}
}
void WriteToRanking(RANKING *ranks, int rankLen) // 分数写入排名文件
{
	int i = 0;
	FILE *fp;
	if ((fp = fopen("ranking.txt", "w")) == NULL)
	{
		FileException();
		return;
	}
	while (i < rankLen)
	{
		if (i != rankLen - 1) // 非最后一行要写入换行符
			fprintf(fp, "%d  %s  %d  %s\n", ranks[i].ranking, ranks[i].user, ranks[i].score[0], ranks[i].datetime);
		else // 最后一行不写入换行符
			fprintf(fp, "%d  %s  %d  %s", ranks[i].ranking, ranks[i].user, ranks[i].score[0], ranks[i].datetime);

		// printf("id=%d,user=%s,s=%d,date=%s\n", ranks[i].ranking, ranks[i].user, ranks[i].score[0], ranks[i].datetime);
		i++;
	}
	fclose(fp);
}

void PrintRanking(RANKING *ranks, int rankLen) // 展示排名内容
{
	int i = 0;
	for (i = 0; i < rankLen; i++)
	{
		printf("%3d,%10s,%3d,%20s\n", ranks[i].ranking, ranks[i].user, ranks[i].score[0], ranks[i].datetime);
	}
}
