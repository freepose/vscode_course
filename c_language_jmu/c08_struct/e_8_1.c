/*输出总分最高学生的成绩信息*/
#include <stdio.h>
struct student
{
	int num;
	char name[10];
	int chinese, english, math;
	int total;
};

int main()
{
	int i, n;
	struct student max, stu;
	printf("请输入学生数:");
	scanf("%d", &n);
	printf("input the student's number,name and course scores\n");
	for (i = 1; i <= n; i++)
	{
		printf("No.%d:", i);
		scanf("%d%s%d%d%d", &stu.num, &stu.name, &stu.chinese,
			  &stu.english, &stu.math);
		stu.total = stu.chinese + stu.english + stu.math;
		if (i == 1)
		{
			max = stu;
		}
		else if (max.total < stu.total)
		{
			max = stu;
		}
	}
	printf("num:%d,name:%s,total:%d\n", max.num, max.name, max.total);
}
