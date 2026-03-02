
// Example 6-3: Logical expression application

#include <stdio.h> 

int main(void)
{
    char ch = 'w';
    int a = 2, b = 0, c = 0;
    float x = 3.0; 

    printf("%d ", a && b);
    printf("%d ", a || b && c);
    printf("%d ", !a && b);
    printf("%d ", a||3+10&&2);
    printf("%d ", !(x == 2));
    printf("%d ", !x == 2);
    printf("%d\n ", ch || b);

    return 0;
}

// 0 1 0 1 1 0 1