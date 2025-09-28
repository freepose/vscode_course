

// Example 3-1: guess number game

#include <stdio.h>

int main()
{
    int number = 70, guess; 

    while (1)
    {
        printf("Please input your guess (1~100): ");
        scanf("%d", &guess);
        if (guess < number)
        {
            printf("Smaller\n");
        }
        else if (guess == number)
        {
            printf("Bingo (equal)\n");
            break;
        }
        else
        {
            printf("Bigger\n");
        }
    }
    return 0;
}