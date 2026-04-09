
#include <stdio.h>
#include <math.h>

void say_hello()
{
    printf("Hello world!");
}

int fact(int n)
{
    int _fact = 1;
    for (int i = 1; i <= n; i++)
    {
        _fact *= i;
    }

    return _fact;
}

int main()
{
    // float y = 0, a = 2.5, x = 3;

    // printf("%f", pow(a, x));

    int n1 = 5, n2 = 6;
    printf("%d! = %d\n", n1, fact(n1));
    
    printf("%d! = %d\n", n2, fact(n2));

    return 0;
}