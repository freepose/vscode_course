#include <stdio.h>
int main()
{
	int moveMountain(int mountainNum, int moveNum);
	int (*funcPoint)() = moveMountain;
	int n, k, countOfGame = 0, playerWin = 0;
	char ifContinue = 'y';
	printf("搬山游戏开始...\n");
	do
	{
		printf("\n 第%d局游戏\n", ++countOfGame);
		printf("-------------\n");
		printf("请输入山的总数：");
		do
		{
			scanf("%d", &n);
			if (n <= 1)
				printf("请输入大于1的数：");
		} while (n <= 1);
		printf("请输入每次搬山允许的最大数（≤%d的正数）：", n);
		do
		{
			scanf("%d", &k);
			if (k > n || k < 1)
				printf("请输入正确的数：");
		} while (k > n || k < 1);
		if ((*funcPoint)(n, k))
			playerWin++;
		printf("\n是否继续玩游戏（Y/N）：");
		do
		{
			ifContinue = getchar();
			if (ifContinue == '\n')
				ifContinue = getchar();
			if (ifContinue != 'y' && ifContinue != 'Y' && ifContinue != 'n' && ifContinue != 'N')
				printf("请输入Y或N：");
		} while (ifContinue != 'y' && ifContinue != 'Y' && ifContinue != 'n' && ifContinue != 'N');
	} while (ifContinue == 'y' || ifContinue == 'Y');
	printf("\n一共玩了%d局游戏\n", countOfGame);
	printf("您和计算机的比分是：%d:%d\n", playerWin, countOfGame - playerWin);
	return 0;
}
int moveMountain(int mountainNum, int moveNum)
{
	int playerWin, playerMove, computerMove;
	do
	{
		printf("请输入本次您想搬山的数量：");
		scanf("%d", &playerMove);
		if (playerMove < 1 || playerMove > moveNum || playerMove > mountainNum)
		{
			printf("您输入的数量无效！\n");
			continue;
		}
		mountainNum -= playerMove;
		if (!mountainNum)
		{
			printf("抱歉，您输了！\n");
			return 0;
		}
		else
		{
			printf("您搬完还剩%d座山\n", mountainNum);
			computerMove = (mountainNum - 1) % (moveNum + 1); // 求出最佳搬山数
			if (!computerMove)
				computerMove = 1;
			mountainNum -= computerMove;
			printf("计算机搬走%d座山\n", computerMove);
			if (mountainNum)
				printf("还剩%d座山\n", mountainNum);
			else
			{
				printf("恭喜，您赢了！\n");
				return 1;
			}
		}
	} while (mountainNum);
}
