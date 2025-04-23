
// Example 8-3: Role exchange.
// There are two roles represented by variables a and b. In order to achieve role exchange, three sets of plans have been formulated, which swap the values of variables a and b through function calls, namely swap1(), swap2(), and swap3(). Please analyze which function can achieve this function.

#include <stdio.h>

int main(void)
{
    int a = 1, b = 2;
    int *pa = &a, *pb = &b;
    void swap1(int x, int y), swap2(int *px, int *py), swap3(int *px, int *py);

    swap1(a, b);
    printf("After calling swap1: a = %d b = %d\n", a, b);

    a = 1;
    b = 2;
    swap2(pa, pb);
    printf("After calling swap2: a = %d b = %d\n", a, b);

    a = 1;
    b = 2;
    swap3(pa, pb);
    printf("After calling swap3: a = %d b = %d\n", a, b);

    return 0;
}

void swap1(int x, int y)
{
    int t;

    t = x;
    x = y;
    y = t;
}

void swap2(int *px, int *py)
{
    int t;

    t = *px;
    *px = *py;
    *py = t;
}

void swap3(int *px, int *py)
{
    int *pt;

    pt = px;
    px = py;
    py = pt;
}

// After calling swap1: a = 1 b = 2
// After calling swap2: a = 2 b = 1
// After calling swap3: a = 1 b = 2