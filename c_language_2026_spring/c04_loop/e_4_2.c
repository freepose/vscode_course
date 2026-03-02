
// Example 4-2: Average and Failures.
// Input a series of student scores and calculate the average score and the number of failures.

#include <stdio.h>
int main(void)
{
    int count, num;    
    double score, total; 

    num = 0;
    total = 0;
    count = 0;
    printf("Enter scores: "); 
    scanf("%lf", &score);   

    while (score >= 0)
    {
        total = total + score; 
        num++;               
        if (score < 60)
        {
            count++;
        }
        scanf("%lf", &score); 
    }

    if (num != 0)
    {
        printf("Average is %.2f\n", total / num);
        printf("Number of failures is %d\n", count);
    }
    else
    {
        printf("Average is 0\n");
    }

    return 0;
}

// Enter scores: 66 88 73 54 82 -1
// Average is 72.25
// Number of failures is 1
