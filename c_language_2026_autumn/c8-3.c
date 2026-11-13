


#include <stdio.h>

void swap1(int x, int y)
{
    printf("x = %d, y = %d\n", x, y);
    int t = x;
    x = y;
    y = t;
    printf("x = %d, y = %d\n", x, y);
}

void swap2(int* p1, int* p2)
{
    printf("p1 %p -> %d, p2 %p = %d\n", p1, *p1, p2, *p2);
    int t = *p1;
    *p1 = *p2;
    *p2 = t;
    printf("p1 %p -> %d, p2 %p = %d\n", p1, *p1, p2, *p2);
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