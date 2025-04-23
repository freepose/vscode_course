#include <stdio.h>
int main()
{
    int x, y, *pointer_x = &x, *pointer_y;
    pointer_y = &y;
    x = 1;
    y = 2;
    printf("%d,%d\n", x, y);
    printf("%d,%d\n", *pointer_x, *pointer_y);
    return 0;
}
