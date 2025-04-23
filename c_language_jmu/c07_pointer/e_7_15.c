#include <stdio.h>
int main()
{
  int a[3][4] = {{0, 1, 2, 3}, {10, 11, 12, 13}, {20, 21, 22, 23}};
  int *p, i;
  p = a[0];
  for (i = 0; i < 12; i++)
  {
    printf("%4d", *(a[0] + i)); // 等价于printf("%4d",*(p+i));
    if (!((i + 1) % 4))
      printf("\n");
  }
  return 0;
}
