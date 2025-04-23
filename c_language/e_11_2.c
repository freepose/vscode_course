
// Example 11-2: 二级指针：指针的指针

#include<stdio.h>

int main()
{
    int a = 10;
    int *pa = &a; // 一级指针：指针
    int **ppa = &pa; // 二级指针：指针的指针

    printf("address = %p, *pa = %d\n", pa, *pa);
    printf("address = %p, *ppa = %lx\n", ppa, *ppa);

    // where is a?
    printf("**ppa = %d, *pa = %d, a = %d\n", **ppa, *pa, a);

    return 0;
}