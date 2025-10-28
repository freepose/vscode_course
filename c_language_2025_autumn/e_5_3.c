

// Example 5-3: Square number calculation using a user-defined function

#include <stdio.h>
#include <math.h>

int IsSquare(int n)
{
    return 1;
}

int is_square(int n)
{
    int root = (int)sqrt(n);
    if (root * root == n)
        return 1;
    return 0;
}

int main()
{
    int num = 16;
    if (is_square(num))
        printf("%d is a perfect square.\n", num);
    else
        printf("%d is not a perfect square.\n", num);
    return 0;
}