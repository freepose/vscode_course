#include <stdio.h>
struct student // 定义学生信息结构体类型
{
	int num;					// 学号
	char name[10];				// 姓名
	int chinese, english, math; // 三门课程成绩
	double total;				// 个人成绩的总分
};

int search_score(struct student *p, int n, int num); // 函数声明

int main()
{
	int i, pos, n, num, course, score;
	struct student students[50]; // 声明结构体数组

	/* 输入n个学生信息 */
	printf("Input n: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Input the info of No.%d:\n", i + 1);
		printf("number:");
		scanf("%d", &students[i].num);
		printf("name:");
		scanf("%s", students[i].name);
		printf("chinese score:");
		scanf("%d", &students[i].chinese);
		printf("english score:");
		scanf("%d", &students[i].english);
		printf("math score:");
		scanf("%d", &students[i].math);
	}

	printf("Input the number of searched student: ");
	scanf("%d", &num); // 输入待查找的学生学号

	pos = search_score(students, n, num); // 调用函数，查找学生

	/*输出查找到的学生信息*/
	if (pos == -1)
	{
		printf("Not found!\n");
	}
	else
	{
		printf("After search:\n");
		printf("num	chinese	english	math\n");
		printf("%d\t%d\t%d\t%d\n", students[pos].num, students[pos].chinese, students[pos].english, students[pos].math);
	}

	return 0;
}
/* 自定义函数，查找学生信息 */
int search_score(struct student *p, int n, int num)
{
	int i, pos;
	for (i = 0; i < n; i++, p++) // 按学号查找
		if (p->num == num)
		{
			break;
		}
	if (i < n)
	{			 /*找到，记录学生的位置*/
		pos = i; // 学生位置
	}
	else
	{
		pos = -1; // 无此学号
	}
	return pos;
}
