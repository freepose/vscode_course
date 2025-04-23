
// Example 3-3: Average score and number of failures. Print the average score and the number of students who failed (score < 60).

#include <stdio.h>
int main(void)
{
    int count, i, n;    
    double score, total;

    printf("Enter n: ");
    scanf("%d", &n);

    total = 0;
    count = 0;

    for (i = 1; i <= n; i++)
    {
        printf("Enter score #%d: ", i);
        scanf("%lf", &score);          
        total = total + score;          
        if (score < 60)
        {
            count++;
        }
    }
    if (n != 0)
    {
        printf("Average = %.2f\n", total / n);
    }
    else
    {
        printf("Average = %.2f\n", 0.0); 
    }

    printf("Number of failures = %d\n", count);

    return 0;
}

// Enter n: 4
// Enter score #1: 60
// Enter score #2: 54
// Enter score #3: 95
// Enter score #4: 73

// Average = 70.25
// Number of failures = 1