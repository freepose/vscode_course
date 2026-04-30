
#include <stdio.h>

void print_array(int *a, int n)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", *(a + i));
    }
    printf("\n"); 
}

int main()
{
    int scores[10] = {67, 88, 76, 90, 56, 95, 72, 83, 80, 92};

    print_array(scores, 10);
    
    return 0;
}