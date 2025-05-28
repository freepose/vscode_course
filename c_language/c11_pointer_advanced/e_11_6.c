
// Example 11-6: Randomly deal cards.
// A deck of cards has 52 cards, 4 suits, and 13 cards of each suit. Use the program to simulate the random dealing process, distribute the 52 cards to 4 people in a rotating manner, and output the dealing results.

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

struct card
{
    int suit;
    int face;
};

void deal(struct card *wdeck)
{
    int i, m, t;
    static int temp[52] = {0};

    srand(time(NULL));
    for (i = 0; i < 52; i++)
    {
        while (1)
        {
            m = rand() % 52;
            if (temp[m] == 0)
            {
                break;
            }
        }
        temp[m] = 1;

        t = (i % 4) * 13 + (i / 4);
        wdeck[t].suit = m / 13;
        wdeck[t].face = m % 13;
    }
}

int main(void)
{
    int i;
    struct card deck[52];
    const char *suit[] = {"Heart", "Diamond", "Club", "Spade"};
    const char *face[] = {"A", "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2"};

    deal(deck);
    for (i = 0; i < 52; i++)
    {
        if (i % 13 == 0)
        {
            printf("Player %d:\n", i / 13 + 1);
        }
        printf("%s of %s\n", face[deck[i].face], suit[deck[i].suit]);
    }

    return 0;
}
