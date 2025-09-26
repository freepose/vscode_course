
#include<stdio.h>

int main(void)
{
    int number = 520, counter = 0;
    int weight = 2;
    int first = 250, second = 175, g, f, s, t;
    
    do {
        printf("%d\t", number % weight);
        number /= weight;
        counter++;
    } while(number > 0);

    printf("%d numbers.\n", counter);

    f = first;
    s = second;
    if (f < s)
    {
        t = s; 
        s = f;
        f = t;
    }
    do {
        g = f % s;
        f = s;
        s = g;
    } while(g > 0);
    
    printf("gcd(%d, %d) = %d\n", first, second, f);
    return 0;
}
