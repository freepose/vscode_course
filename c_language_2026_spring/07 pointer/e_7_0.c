
// What is a pointer?

#include <stdio.h>

int main()
{
    int n = 123;
    int *p = &n;

    printf("%p -> %d\n", p, n);
    *p = 456;
    printf("n = %d", n);

    return 0;
}