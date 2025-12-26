
// Example 11-5: 汉字占两个字节

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *poem[4] = {
        "一叶轻舟向东流，", 
        "帆梢轻握杨柳手。",
        "风纤碧波微起舞，", 
        "顺水任从雅客悠。"};
    int n_sentences = sizeof(poem) / sizeof(poem[0]);

    // get first chinese character of each sentence
    char *buffer = (char *)malloc(n_sentences * sizeof(char) + 1);

    for (int i = 0; i < n_sentences; i++)
    {
        // buffer[2 * i + 0] = poem[i][0];
        // buffer[2 * i + 1] = poem[i][1];

        // memcpy(buffer + 2 * i, poem[i], 2);
        strncpy(buffer + 2 * i, poem[i], 2);
    }
    buffer[2 * n_sentences] = '\0';

    printf("%s\n", buffer);

    return 0;
}