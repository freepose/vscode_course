#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int lottery[7] = {0};
	int *lotteryPoint[7];
	int pointIdx, lotteryIdx = 0, index, randNum;
	int minIdx, sortTime, cmpTime, *tmpPoint;
	srand(time(0));
	while (lotteryIdx < 7)
	{
		randNum = rand() % 36 + 1;
		for (index = 0; index < lotteryIdx; index++)
			if (lottery[index] == randNum)
				break;
		if (index == lotteryIdx)
			lottery[lotteryIdx++] = randNum;
	}
	printf("机选初始结果为：");
	for (lotteryIdx = 0; lotteryIdx < 7; lotteryIdx++)
		printf("%d  ", lottery[lotteryIdx]);
	printf("\n");
	for (pointIdx = 0; pointIdx < 7; pointIdx++)
		lotteryPoint[pointIdx] = &lottery[pointIdx];
	for (sortTime = 0; sortTime < 7; sortTime++)
	{
		minIdx = sortTime;
		for (cmpTime = sortTime + 1; cmpTime < 7; cmpTime++)
			if (*lotteryPoint[minIdx] > *lotteryPoint[cmpTime])
				minIdx = cmpTime;
		tmpPoint = lotteryPoint[sortTime];
		lotteryPoint[sortTime] = lotteryPoint[minIdx];
		lotteryPoint[minIdx] = tmpPoint;
	}
	printf("排序后的结果为：");
	for (pointIdx = 0; pointIdx < 7; pointIdx++)
		printf("%d  ", *lotteryPoint[pointIdx]);
	printf("\n");
	return 0;
}
