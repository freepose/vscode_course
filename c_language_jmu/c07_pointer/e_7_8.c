#include <stdio.h>
int main()
{
	double stuScore[10], maxScore;
	double *scorePoint = stuScore;
	int stuIdx;
	printf("请输入10位同学的成绩:\n");
	for (stuIdx = 0; stuIdx < 10; stuIdx++)
		scanf("%lf", scorePoint++);
	maxScore = stuScore[0];
	for (stuIdx = 0; stuIdx < 10; stuIdx++)
		if (stuScore[stuIdx] > maxScore)
			maxScore = stuScore[stuIdx];
	printf("最高分为：%.1lf\n", maxScore);
	return 0;
}
