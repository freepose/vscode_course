#include <stdio.h>
int main()
{
	int iCourse, iStu, stuScore[5][3];
	double sumScore, avgCourse[3], avgAll;
	printf("请输入每门课（共3门）5位学生的成绩:\n");
	for (iCourse = 0; iCourse < 3; iCourse++) // 计算每门课的平均分
	{
		sumScore = 0;
		for (iStu = 0; iStu < 5; iStu++)
		{
			scanf("%d", &stuScore[iStu][iCourse]);
			sumScore += stuScore[iStu][iCourse];
		}
		avgCourse[iCourse] = sumScore / 5;
	}
	// 计算总平均值
	avgAll = (avgCourse[0] + avgCourse[1] + avgCourse[2]) / 3;
	// 输出每门课的平均分和总平均分
	printf("语文的平均分:%.1f\n", avgCourse[0]);
	printf("数学的平均分:%.1f\n", avgCourse[1]);
	printf("英语的平均分:%.1f\n", avgCourse[2]);
	printf("总的平均分:%.1f\n", avgAll);
	return 0;
}
