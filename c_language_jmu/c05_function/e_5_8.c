#include <stdio.h>
void fun1(), fun2(), fun3();
int main()
{
	printf("1111\n");
	fun2();
	printf("7777\n");
	return 0;
}
void fun1()
{
	printf("3333\n");
	fun3();
	printf("5555\n");
}
void fun2()
{
	printf("2222\n");
	fun1();
	printf("6666\n");
}
void fun3()
{
	printf("4444\n");
}
