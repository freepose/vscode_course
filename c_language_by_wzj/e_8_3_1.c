
// Example 8-3: changes values in user-defined function

// How to change values in user-defined function using pointers

#include <stdio.h>

void change(int *p)
{
    *p = 100;
}

void swap(int *pf, int *ps)
{
    int temp = *pf;
    *pf = *ps;
    *ps = temp;
}

int main()
{
    int a = 1, b = 2;

    printf("before change: a = %d\n", a); // Output: n = 1
    change(&a);
    printf("after change: a = %d\n", a); // Output: n = 1

    printf("before swap: a = %d, b = %d\n", a, b); // Output: n = 1, m = 2
    swap(&a, &b);
    printf("after swap: a = %d, b = %d\n", a, b); // Output: n = 1, m = 2

    return 0;
}