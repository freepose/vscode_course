

#include <stdio.h>

int main()
{
    int a;
    int *p = &a;

    scanf("%d", p);
    printf("%p -> %d\n", p, *p);
    
    return 0;
}