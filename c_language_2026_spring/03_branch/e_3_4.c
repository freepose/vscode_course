
// Guess number

#include <stdio.h>

int main()
{
    int guess_number = 42;
    int user_number;

    scanf("%d", &user_number);

    if (user_number > guess_number)
    {
        printf("Too high!\n");
    }
    else if (user_number == guess_number)
    {
        printf("Congratulations! You guessed the number.\n");
    }
    else
    {
        printf("Too low!\n");
    }

    return 0;
}