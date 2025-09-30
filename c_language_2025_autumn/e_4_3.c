
// Example 4-3: count digits in an integer number

#include <stdio.h>

int main()
{
    int n = -12345, counter = 0;

    do {  
        printf("%d\t", n % 10);
        n = n / 10;
    } while (n != 0);

    return 0;
}