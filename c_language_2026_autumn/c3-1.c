

#include <stdio.h>

int main()
{
    int number = 0, to_guess = 42;

    scanf("%d", &number);

    // printf("%d", number);

    if (number > to_guess)
    {
        printf("bigger\n");
    }
    else if (number == to_guess)
    {
        printf("bingo\n");
    }
    else
    {
        printf("smaller\n");
    }


    return 0;
}