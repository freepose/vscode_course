#include <stdio.h>
int main()
{
	char ch;
	ch = getchar();
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		printf("Yes");
	else
		printf("No");
	return 0;
}
