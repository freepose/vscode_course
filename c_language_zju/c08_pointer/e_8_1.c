
// Example 8-1: Simulate a password lock game using pointers.

#include <stdio.h>

int main(void)
{
    int x = 5342;
    int *p = NULL;

    p = &x;

    printf("If I know the name of the variable, I can get it's value by name: %d\n ", x);

    printf("If I know the address of the variable is: %x, then I also can get it's value by address: %d\n", p, *p);

    return 0;
}

// If I know the name of the variable, I can get it's value by name: 5342
// If I know the address of the variable is: <Virtual address>, then I also can get it's value by address: 5342