
// Example 11-5: Decode the acrostic poem.
// The so-called acrostic poem is that the first character of each line of a poem is connected together, and the content composed is the hidden information of the poem. Write a program to input an English acrostic poem, decode the acrostic poem and output its hidden information. The input acrostic poem is less than 20 lines, and each line does not exceed 80 characters. Use # as the input end mark, and use dynamic memory allocation method to process string input.

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main(void)
{
    int i, n = 0;
    char *poem[20], str[80], mean[20];

    gets(str);
    while (str[0] != '#')
    {
        poem[n] = (char *)malloc(sizeof(char) * (strlen(str) + 1));
        strcpy(poem[n], str);
        gets(str);
    }

    for (i = 0; i < n; i++)
    {
        mean[i] = *poem[i];
        free(poem[i]);
    }
    mean[i] = '\0';

    puts(mean);

    return 0;
}

// I come into a dream
// Leaves fall down but spring
// over a lake birds flying
// village have its nice morning
// everywhere can feel happiness
// Years have never been
// owners don't need anything
// until the sun bring another wind
// #
// ILoveYou