
// Example 8-7: Use pointers to calculate the number of array elements and the number of storage units of array elements.

#include <stdio.h>

int main(void)
{
    double a[2], *p, *q;

    p = &a[0];
    q = p + 1;
    printf("%d\n", q - p);
    printf("%d\n", (int)q - (int)p);

    return 0;
}

// 1
// 8