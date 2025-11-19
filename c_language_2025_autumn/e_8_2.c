
// Example 8-2: swap()

#include <stdio.h>

void swap1(int x, int y)
{
    // from real parameters to formal parameters: copy the value
    printf("Inside swap function before swap: x = %d, y = %d\n", x, y);
    int temp = x;
    x = y;
    y = temp;
}

void swap2(int *x, int *y)
{
    // from real parameters to formal parameters: copy the address
    printf("Inside swap function before swap: *x = %d, *y = %d\n", *x, *y);
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 2, b = 3;
    printf("Before swap: a = %d, b = %d\n", a, b);

    // swap1(a, b);
    swap2(&a, &b);

    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}