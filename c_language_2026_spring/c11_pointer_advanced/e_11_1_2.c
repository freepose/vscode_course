
// Example 11-1-2: Pointer array discussion

#include <stdio.h>

#include <string.h>

int main(void)
{
    int i;
    const char *color[5] = {"red", "blue", "yellow", "green", "black"};

    printf("%x\n", color);
    for (i = 0; i < 5; i++)
    {
        printf("%x %s %c\n", color[i], color[i], *color[i]);
    }

    for (i = 0; i < 5; i++)
    {
        printf("%x %s %c\n", color[i] + 1, color[i] + 1, *color[i] + 1);
    }

    return 0;
}
