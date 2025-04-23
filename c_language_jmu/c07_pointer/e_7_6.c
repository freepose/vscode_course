#include <stdio.h>
int main()
{
  int a[] = {1, 11, 21}, *p = a, i = 0, j;
  j = (*p)++;
  printf("j=%d,a[0]=%d,*p=%d,", j, a[i], *p);
  printf("*(p++)=%d,", *(p++));
  printf("*(++p)=%d\n", *(++p));
  return 0;
}
