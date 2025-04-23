#include <stdio.h>
int main()
{
	void sort();
	char *name[] = {"刘一", "陈二", "张三", "李四", "王五", "赵六", "孙七", "周八", "吴九", "郑十"};
	int idx, num;
	num = sizeof(name) / sizeof(char *);
	sort(name, num);
	printf("名单顺序如下：\n");
	for (idx = 0; idx < num; idx++)
		printf("%s\n", name[idx]);
	return 0;
}
void sort(char **pToP, int num)
{
	char *tmpPoint;
	int i, j;
	for (i = 0; i < num - 1; i++)
		for (j = i + 1; j < num; j++)
			if (strcmp(*(pToP + i), *(pToP + j)) > 0)
			{
				tmpPoint = *(pToP + i);
				*(pToP + i) = *(pToP + j);
				*(pToP + j) = tmpPoint;
			}
}
