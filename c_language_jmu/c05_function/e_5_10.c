#include <stdio.h>
void hanio(int n, char a, char b, char c);
int main()
{
   int n;
   printf("input the number of disk:");
   scanf("%d", &n);
   printf("the steps for %d disk are:\n", n);
   hanio(n, 'a', 'b', 'c');
   return 0;
}
/* 搬动n个盘，从a到c, b为中间过渡 */
void hanio(int n, char a, char b, char c)
{
   if (n == 1)
      printf("%c-->%c\n", a, c);
   else
   {
      hanio(n - 1, a, c, b);
      printf("%c-->%c\n", a, c);
      hanio(n - 1, b, a, c);
   }
}
