
// Example 4-0: if vs while

#include <stdio.h>

int main() 
{
    int a = 0;
    if (a < 5) 
    {
        a = a + 1;
    }

    printf("Value of a after if statement: %d\n", a);

    a = 0;
    while (a < 5) 
    {
        a = a + 1;
    }
    printf("Value of a after while statement: %d\n", a);

    return 0;
}