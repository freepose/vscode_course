#include <stdio.h>
int main()
{
  void swap(int *p1, int *p2);
  int i, j;
  int *pointer_i = &i, *pointer_j = &j;
  printf("请输入两个整数：");
  scanf("%d%d", &i, &j);
  printf("输入的值：i=%d,j=%d\n", i, j);
  if (i < j)
    swap(pointer_i, pointer_j);
  printf("排好序后的结果：i=%d,j=%d\n", i, j);
  return 0;
}
void swap(int *p1, int *p2)
{
  int t = *p1;
  *p1 = *p2;
  *p2 = t;
}
