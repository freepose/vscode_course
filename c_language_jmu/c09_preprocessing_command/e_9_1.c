#include <stdio.h>
#define PI 3.1415926
#define S(r) PI *r *r
int main()
{
  float a, area;
  printf("请输入圆的半径：");
  scanf("%f", &a);
  area = S(a);
  printf("半径为%.2f的圆面积为：%.2f\n", a, area);
  return 0;
}
