
// Example 8-2: Address and Indirect Access Operators Example

#include <stdio.h>

int main(void)
{
    int a = 3, *p;

    p = &a;
    printf("a = %d, *p = %d\n", a, *p);

    *p = 10;
    printf("a = %d, *p = %d\n", a, *p);

    printf("Enter a: ");
    scanf("%d", &a);
    printf("a = %d, *p = %d\n", a, *p);

    (*p)++;
    printf("a = %d, *p = %d\n", a, *p);

    return 0;
}

// a = 3, *p = 3
// a = 10, *p = 10
// Enter a: 5
// a = 5, *p = 5
// a = 6, *p = 6