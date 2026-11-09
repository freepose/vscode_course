
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

int main()
{
    // char buffer[MAX_LEN] = {'a', 'b', 'c', 'b', 'a', '\0'};
    char buffer[MAX_LEN] = {0};
    
    scanf("%s", buffer);
    int len = strlen(buffer);
    int i = 0, j = len - 1;

    printf("%s -> length: %d\n", buffer, len);

    while (i < j)
    {
        if (buffer[i] == buffer[j])
        {
            i++;
            j--;
        }
        else
        {
            break;
        }
    }

    if (i >= j)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}