
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

int main()
{
    char buff1[MAX_LEN] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char buff2[MAX_LEN] = {'w', 'o', 'r', 'l', 'd', '\0'};

    printf("buff1 vs. buff2 = %d\n", strcmp(buff1, buff2));

    return 0;
}