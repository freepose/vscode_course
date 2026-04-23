
// swap two numbers in a function

#include <stdio.h>

void swap1(int f, int s)
{
    int t = f;
    f = s;
    s = t;
}

void swap2(int* f, int* s)
{
    int t = *f;
    *f = *s;
    *s = t;
}

int main()
{
    int a = 1, b = 3;

    printf("a = %d, b = %d\n", a, b);
    swap2(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}