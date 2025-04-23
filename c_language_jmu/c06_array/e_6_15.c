#include <stdio.h>
#include <string.h>
#include <time.h>
int main()
{
	char name[15][20] = {"刘一", "陈二", "张三", "李四", "王五", "赵六", "钱七", "贾八", "吴九", "周十", "田甲", "郑乙", "孙丙", "杨丁", "马戊"};
	char winner[15][20]; // 存放中奖者名单
	char tempName[20];
	int num, i, j, numOfWin, iWin = 0;
	printf("请输入中奖人数(<10):");
	scanf("%d", &numOfWin);
	for (i = 0; i < numOfWin; i++)
	{
		srand((unsigned)time(NULL)); // 使用系统当前时间作为随机种子生成随机数
		num = rand() % (15 - i);	 // 根据rand()和剩余中奖人数获得中奖号码
		strcpy(winner[iWin++], name[num]);
		for (j = num; j < 15 - i - 1; j++) // 从原来的剩余名单中删除中奖者
			strcpy(name[j], name[j + 1]);
		strcpy(name[j], "");
	}

	// 对中奖名单进行排序
	for (i = 0; i < numOfWin - 1; i++)
		for (j = 0; j < numOfWin - i - 1; j++)
			if (strcmp(winner[j], winner[j + 1]) > 0)
			{
				strcpy(tempName, winner[j]);
				strcpy(winner[j], winner[j + 1]);
				strcpy(winner[j + 1], tempName);
			}
	for (i = 0; i < numOfWin; i++)
		printf("%s  ", winner[i]);
	printf("\n");
	return 0;
}
