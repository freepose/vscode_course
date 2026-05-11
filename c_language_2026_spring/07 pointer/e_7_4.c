
// 交换两个数

#include <stdio.h>

void swap1(int f, int s)
{
    int temp = f;
    f = s;
    s = temp;

}

void swap2(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int first = 1, second = 2;

    printf("first = %d, second = %d\n", first, second);

    // swap1(first, second);
    swap2(&first, &second);

    printf("first = %d, second = %d\n", first, second);

    return 0;
}