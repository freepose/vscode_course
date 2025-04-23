#include <stdio.h>
int main()
{
	int stuScore1, stuScore2, stuScore3, stuScore4, stuScore5, stuScore6, stuScore7, stuScore8, stuScore9, stuScore10;
	int count = 0;
	float avgScore;
	printf("请输入10位同学的成绩：");
	scanf("%d%d%d%d%d%d%d%d%d%d", &stuScore1, &stuScore2, &stuScore3, &stuScore4, &stuScore5, &stuScore6, &stuScore7, &stuScore8, &stuScore9, &stuScore10);
	avgScore = (stuScore1 + stuScore2 + stuScore3 + stuScore4 + stuScore5 + stuScore6 + stuScore7 + stuScore8 + stuScore9 + stuScore10) / 10.0;
	printf("10位同学的平均分为：%f\n", avgScore);
	if (stuScore1 > avgScore)
		count++;
	if (stuScore2 > avgScore)
		count++;
	if (stuScore3 > avgScore)
		count++;
	if (stuScore4 > avgScore)
		count++;
	if (stuScore5 > avgScore)
		count++;
	if (stuScore6 > avgScore)
		count++;
	if (stuScore7 > avgScore)
		count++;
	if (stuScore8 > avgScore)
		count++;
	if (stuScore9 > avgScore)
		count++;
	if (stuScore10 > avgScore)
		count++;
	printf("10位同学中成绩大于平均分的人数为：%d\n", count);
	return 0;
}
