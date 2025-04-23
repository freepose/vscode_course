#include <stdio.h>
int main()
{
	int year, mon, day, hour, min, sec;
	printf("请以YYYY-MM-DD HH:MM:SS形式输入日期和时间：\n");
	scanf("%d-%d-%d %d:%d:%d", &year, &mon, &day, &hour, &min, &sec);
	printf("输入的日期为：%d-%d-%d\n", year, mon, day);
	printf("输入的时间为：%d:%d:%d\n", hour, min, sec);
	return 0;
}
