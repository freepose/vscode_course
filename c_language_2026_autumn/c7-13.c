
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

int main()
{
    char buffer[MAX_LEN] = {0};
    int number = 0;

    scanf("%s", buffer);
    int len = strlen(buffer);

    for (int i = 0; i < len; i++)
    {
        if (buffer[i] >= '0' && buffer[i] <= '9')
        {
            int n = buffer[i] - '0';
            number = number * 10 + n;
        }
    }

    printf("number = %d\n", number);

    return 0;
}