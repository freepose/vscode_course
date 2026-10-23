
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int x;  // randomly generated number
    int counter = 7;
    int input = 0;

    srand(time(0));
    x = rand() % 100 + 1;

    // printf("%d", x);

    for (int i = 0; i < counter; i++)
    {
        scanf("%d", &input);

        if (input > x)
        {
            printf("bigger\n");
        }
        else if (input == x)
        {
            printf("bingo, it's %d\n", x);
            break;
        }
        else
        {
            printf("smaller\n");
        }

    }

    return 0;
}

