#include <stdio.h>

int main()
{
    int num_january;
    int num_february;
    int num_march;

    float num_average;

    printf("Enter the sales in January, February, and March: ");
    scanf("%d %d %d", &num_january, &num_february, &num_march);

    num_average = (num_january + num_february + num_march) / 3.0;
    printf("The average = %f\n", num_average);

    return 0;
}