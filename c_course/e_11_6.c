
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char* colors[20] = {0};
    char buffer[256] = {0};
    int counter = 0;
    do
    {
        scanf("%s", buffer);
        // 让指针指向新开辟的空间
        colors[counter] = (char*)malloc(sizeof(char) * strlen(buffer) + 1); 
        strcpy(colors[counter], buffer);
        counter++;
    } while (buffer[0] != '#');

    counter--;

    for (int i = 0; i < counter; i++)
    {
        printf("%s\n", colors[i]);
    }
    
    return 0;
}