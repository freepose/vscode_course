
// Example 6-5: Count the number of words in a line of input characters.
// Where a "word" is defined as a string of characters that does not contain spaces, and words are separated by spaces, which can be multiple.

#include <stdio.h>

int main(void)
{
    int cnt, word;
    char ch;

    word = cnt = 0;
    printf("Input characters: ");
    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ')
        {
            word = 0;
        }
        else if (word == 0)
        {
            word = 1;
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}

// Input characters: This sentence contains five words.
// 5