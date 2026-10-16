
#include <stdio.h>

int max(int f, int s)
{
    // if (f > s)
    // {
    //     return f;
    // }
    // else if (f == s)
    // {
    //     return f;
    // }
    // else
    // {
    //     return s;
    // }
    return f > s ? f : s;
}

int main()
{
    int first = 11, second = 2;

    printf("max(%d, %d) = %d", first, second, max(first, second));
    return 0;
}