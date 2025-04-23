#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printCard(int pokerPoint);
void dealCard(int playerCard[4][13]);
void sortCard(int playerCard[4][13]);

void printCard(int pokerPoint)
{
	switch (pokerPoint / 13)
	{
	case 0:
		putchar(6);
		break;
	case 1:
		putchar(3);
		break;
	case 2:
		putchar(5);
		break;
	case 3:
		putchar(4);
		break;
	}
	putchar(' ');
	switch (pokerPoint % 13)
	{
	case 10:
		printf("%-4c", 'J');
		break;
	case 11:
		printf("%-4c", 'Q');
		break;
	case 12:
		printf("%-4c", 'K');
		break;
	case 0:
		printf("%-4c", 'A');
		break;
	default:
		printf("%-4d", pokerPoint % 13 + 1);
	}
}

void dealCard(int playerCard[4][13]) // 把扑克牌随机发给4个玩家，并对每个人手上的牌进行排序
{
	int dealedCard[52];
	int numOfCardDealt = 0, faceOfCardDealt, flag, i;
	srand((unsigned)time(NULL));

	// 控制发52张牌
	while (numOfCardDealt < 52)
	{
		faceOfCardDealt = rand() % 52; // 产生0~51之间的随机数
		// 查找新产生的随机数是否已经存在
		for (flag = 1, i = 0; i < numOfCardDealt && flag; i++)
			if (dealedCard[i] == faceOfCardDealt)
				flag = 0;
		if (flag)
		{
			dealedCard[numOfCardDealt] = faceOfCardDealt;
			playerCard[numOfCardDealt % 4][numOfCardDealt / 4] = faceOfCardDealt;
			numOfCardDealt++;
		}
	}
	sortCard(playerCard);
}

void sortCard(int playerCard[4][13])
{
	int timesOfSort, timesOfCmp, numOfPlayer, max, tempCard;
	// 对玩家手上的牌进行排序
	for (numOfPlayer = 0; numOfPlayer < 4; numOfPlayer++)
		for (timesOfSort = 0; timesOfSort < 12; timesOfSort++)
		{
			max = timesOfSort;
			for (timesOfCmp = timesOfSort + 1; timesOfCmp < 13; timesOfCmp++)
				if (playerCard[numOfPlayer][max] < playerCard[numOfPlayer][timesOfCmp])
					max = timesOfCmp;
			tempCard = playerCard[numOfPlayer][timesOfSort];
			playerCard[numOfPlayer][timesOfSort] = playerCard[numOfPlayer][max];
			playerCard[numOfPlayer][max] = tempCard;
		}
}

int main()
{
	int playerCard[4][13];
	int play, i;
	dealCard(playerCard);
	for (play = 0; play < 4; play++)
	{
		printf("第%d个玩家手上的牌是：", play + 1);
		for (i = 0; i < 13; i++)
			printCard(playerCard[play][i]);
		printf("\n");
	}
	return 0;
}
