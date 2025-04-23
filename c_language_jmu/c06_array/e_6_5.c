#include <stdio.h>
int main()
{
	int score[11];
	int i, j, tempScore;
	printf("请输入10位同学的成绩:\n");
	for (i = 1; i < 11; i++)
		scanf("%d", &score[i]);
	for (i = 1; i < 10; i++)
		for (j = 1; j < 11 - i; j++)
			if (score[j] < score[j + 1])
			{
				tempScore = score[j];
				score[j] = score[j + 1];
				score[j + 1] = tempScore;
			}
	printf("排好序的成绩如下：\n");
	for (i = 1; i < 11; i++)
	{
		printf("%-4d", score[i]);
	}
	return 0;
}
