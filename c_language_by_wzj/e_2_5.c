
#include <stdio.h>

int main()
{
    int n = 2;

    switch (n)
    {
    case 1:  n = n + 1;  break;
    case 2:  n = n + 2;  break;
    default: n = n + 3;  
    }

    printf("n = %d", n);
    return 0;
}