
// Example 4-8-2: Find the maximum value.
// Input a batch of students' scores and find the highest score.

#include <stdio.h>

int main(void)
{
    int mark, max;

    printf("Enter marks:");
    scanf("%d", &mark);
    max = mark;

    while (mark >= 0)
    {
        if (max < mark)
        {
            max = mark;
        }
        scanf("%d", &mark);
    };
    printf("Max = %d\n", max);

    return 0;
}

// Enter marks: 67 88 73 54 82 -1
// Max = 88