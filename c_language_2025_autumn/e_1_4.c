
// �ó������1��100�ĺ�

#include <stdio.h>

int main()
{
    int start = 0;
    int end = 100;
    int sum = 0;

    for (int i = start; i <= end; i = i + 6)
    {
        sum += i;
    }

    printf("%d\n", sum);

    return 0;
}