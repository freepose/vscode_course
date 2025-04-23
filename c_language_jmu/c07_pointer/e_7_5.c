#include <stdio.h>
int main()
{
	/*
	数组PokerNum表示13个盒子，初始都为空（0）
	numOfPoker表示要放进盒子的牌面数字
	indexOfPoker用于计数空盒子从而确定牌要放进哪个盒子
	indexOfEmpty表示当前数到的空盒子的下标
	*/
	int PokerNum[13] = {0};
	int *pointOfPoker = PokerNum;
	int numOfPoker, indexOfPoker, indexOfEmpty = 0;

	// 13张牌循环13次
	for (numOfPoker = 1; numOfPoker <= 13; numOfPoker++)
	{
		indexOfPoker = 0;
		do
		{
			indexOfEmpty = indexOfEmpty % 13;
			if (PokerNum[indexOfEmpty]) // 盒子非空
				indexOfEmpty++;
			else // 盒子为空
			{	 // 计数空盒子正好等于牌面数字,将牌放入该空盒子
				if (indexOfPoker + 1 == numOfPoker)
					PokerNum[indexOfEmpty] = numOfPoker;
				indexOfEmpty++;
				indexOfPoker++;
			}
		} while (indexOfPoker < numOfPoker); // 寻找indexOfPoker
	}
	printf("魔术师手中的牌原始次序是:\n");
	for (indexOfPoker = 0; indexOfPoker < 13; indexOfPoker++)
		printf("%d ", *(pointOfPoker + indexOfPoker));
	printf("\n");
	return 0;
}
