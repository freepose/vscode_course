
// Example 8-3: changes values in user-defined function

#include <stdio.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int x1 = 5432, x2 = 1234;

    printf("x1 = %d, x2 = %d\n", x1, x2);
    swap(&x1, &x2);
    printf("x1 = %d, x2 = %d\n", x1, x2);

    return 0;
}