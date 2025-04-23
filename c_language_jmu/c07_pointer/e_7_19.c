#include <stdio.h>
#include <string.h>
int main()
{
	void sort();
	char *name[] = {"刘一", "陈二", "张三", "李四", "王五", "赵六", "孙七", "周八", "吴九", "郑十"};
	int idx, num;
	num = sizeof(name) / sizeof(char *); // 计算数组name的元素个数
	sort(name, num);
	printf("名单顺序如下：\n");
	for (idx = 0; idx < num; idx++)
		printf("%s\n", name[idx]);
	return 0;
}
void sort(char *name[], int num)
{
	char *tmpPoint;
	int i, j;
	for (i = 0; i < num - 1; i++)
		for (j = i + 1; j < num; j++)
			if (strcmp(name[i], name[j]) > 0)
			{
				tmpPoint = name[i];
				name[i] = name[j];
				name[j] = tmpPoint;
			}
}
