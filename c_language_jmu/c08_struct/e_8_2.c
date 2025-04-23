/* 学生成绩排序 */
#include <stdio.h>
struct student // 定义学生信息结构体类型
{
	int num;					// 学号
	char name[10];				// 姓名
	int chinese, english, math; // 三门课程成绩
	int total;					// 个人总分
} students[50], b[50];

int main()
{
	int i, n;
	int count_total(struct student s);
	void insert(struct student a[], int n);
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
		students[i].total = count_total(students[i]); // 计算总分
	}

	insert(students, n); // 使用插入排序法为结构体数组排序
	/* 输出排序后的信息 */
	printf("num\t name\t total\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\t %s\t %d\n", b[i].num, b[i].name, b[i].total);
	}
	return 0;
}

void insert(struct student a[], int n)
{
	int i, j, x;
	b[0] = a[0]; // 排序开始
	for (i = 1; i < n; i++)
	{ // i代表排到第i个数了
		for (j = 0; j < n; j++)
		{ // j代表，对比到第几个数了
			if (a[i].total > b[i - j - 1].total && i - j - 1 == 0)
			{ // 插入的数比第0个数都要小，要放到开头
				for (x = i; x > i - j - 1; x--)
				{ // 后面的元素往后移一个位置
					b[x] = b[x - 1];
				}
				b[0] = a[i];
				break;
			}
			if (a[i].total < b[i - j - 1].total)
			{ // 检测插入元素的位置是i-j-1的后一个,也就是i-j位置
				for (x = i; x > i - j; x--)
				{ // i-j-1后后面的元素后移一个位置
					b[x] = b[x - 1];
				}
				b[i - j] = a[i]; // 在i-j位置插入元素
				break;
			}
		}
	}
}

int count_total(struct student s) // 计算个人成绩的总分
{
	return (s.math + s.english + s.chinese);
}
