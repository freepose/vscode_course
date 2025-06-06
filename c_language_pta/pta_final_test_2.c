

#include <stdio.h>

void main()
{
    int aa[5][5] = {{1, 2, 3, 4}, {5, 6, 1, 8}, {5, 9, 10, 2}, {1, 2, 5, 6}};
    int i, s = 0;
    for (i = 0; i < 4; i++)
        s += aa[i][2];
    printf("%d", s);
}