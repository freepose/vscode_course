
// Example 2-5: The Power of perseverance

// result = initial * (1 + factor) ^ days

#include <stdio.h>
#include <math.h>   // for `pow` function

int main()
{
    int days;
    double initial, factor, result;

    printf("Enter initial: ");
    scanf("%lf", &initial);

    printf("Enter daily interest rate: ");
    scanf("%lf", &factor);

    printf("Enter number of days: ");
    scanf("%d", &days);

    result = initial * pow((1 + factor), days); // use `pow` function to calculate power
    printf("result = %.2f\n", result);

    return 0;
}

// Enter initial: 1.0
// Enter daily interest rate: 0.01
// Enter number of days: 365
// result = 37.78

// three scanf statements can be combined into one statement
// scanf("%lf %lf %d", &initial, &factor, &days);