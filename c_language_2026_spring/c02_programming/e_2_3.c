
// Example 2-3: convert fahr value to celsius value

#include <stdio.h>

int main()
{
    int celsius, fahr;

    fahr = 100;
    celsius = 5 * (fahr - 32) / 9;

    printf("fahr=%d, celsius=%d\n", fahr, celsius);

    return 0;
}