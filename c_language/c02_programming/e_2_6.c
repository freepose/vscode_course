
// Example 2-6: given fahr in range [lower, uppper], print fahr-celsius conversion table. 
//              Each time fahr is increased by 1. celsius = 5 * (fahr - 32) / 9

#include <stdio.h>

int main()
{
    int lower, upper, fahr;
    double celsius;

    printf("Fahr\tCelsius\n");

    printf("Enter lower:");
    scanf("%d", &lower);
    printf("Enter upper:");
    scanf("%d", &upper);

    if (lower <= upper)
    {
        for (int fahr = lower; fahr <= upper; fahr++)
        {
            celsius = 5.0 * (fahr - 32) / 9; // convert fahr to celsius
            printf("%4d\t%6.1f\n", fahr, celsius); // print fahr and celsius values
        }
    }
    else
    {
        printf("Invalid Value!\n");
    }

    return 0;
}