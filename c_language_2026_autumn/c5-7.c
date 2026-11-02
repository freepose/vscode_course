
#include <stdio.h>

void swap(int f, int s)
{
    int t = f;
    f = s;
    s = t;
}

int main()
{
    int first = 1;
    int second = 2;

    printf("first = %d, second = %d\n", first, second);
    swap(first, second);
    printf("first = %d, second = %d\n", first, second);

    return 0;
}