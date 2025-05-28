
// Example 4-8-1: Find the maximum value.
// Input a batch of students' scores and find the highest score.

#include <stdio.h>

int main(void)
{
    int i, mark, max, n;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter %d marks: ", n);
    scanf("%d", &mark);
    max = mark;
    for (i = 1; i < n; i++)
    {
        scanf("%d", &mark);
        if (max < mark)
        {
            max = mark;
        }
    }
    printf("Max = %d\n", max);

    return 0;
}

// Enter n: 5
// Enter 5 marks: 67 88 73 54 82
// Max = 88