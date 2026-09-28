
// // What is a pointer?

// #include <stdio.h>

// int main()
// {
//     int n = 123;
//     int *p = &n;

//     printf("%p -> %d\n", p, n);
//     *p = 456;
//     printf("n = %d", n);

//     return 0;
// }

#include <stdio.h>
#define MA(x, y) (x) * (y)

int main()
{
    int i = 2;
    i = 3 / MA(i, i + 2) + 5;
    printf("%d\n", i);
    
    return 0;
}