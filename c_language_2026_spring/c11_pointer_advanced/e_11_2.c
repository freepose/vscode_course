
// Example 11-2: Two-level pointer operation example

#include <stdio.h>

int main(void)
{
    int a, b, t;
    int *pa = &a, *pb = &b, *pt;
    int **ppa = &pa, **ppb = &pb, **ppt;

    a = 10, b = 20;
    printf("%d %d %d %d %d %d\n", a, b, *pa, *pb, **ppa, **ppb);

    ppt = ppb;
    ppb = ppa;
    ppa = ppt;
    printf("%d %d %d %d %d %d\n", a, b, *pa, *pb, **ppa, **ppb);

    pt = pb;
    pb = pa;
    pa = pt;
    printf("%d %d %d %d %d %d\n", a, b, *pa, *pb, **ppa, **ppb);

    t = b;
    b = a;
    a = t;
    printf("%d %d %d %d %d %d\n", a, b, *pa, *pb, **ppa, **ppb);

    return 0;
}
