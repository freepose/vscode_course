
// 7-10 抓老鼠啊~亏了还是赚了？

#include <stdio.h>

int main()
{
    int c;
    int day = 0;
    int must_mouse = 0; // future days that must send a mouse (from 'C'), counts down
    int no_mouse = 0;   // future days with no mouse (from 'X' or 'T'), counts down
    int profit = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '$')
            break;
        if (c == '\n' || c == '\r' || c == ' ')
            continue;

        day++;

        int appear;
        if (day == 1)
            appear = 1;
        else if (must_mouse > 0)
            appear = 1;
        else if (no_mouse > 0)
            appear = 0;
        else
            appear = 1;

        char out;
        if (appear)
        {
            if (c == 'X')
            {
                out = 'U';
            }
            else if (c == 'T')
            {
                out = 'D';
            }
            else
            { // 'C'
                out = '!';
            }
        }
        else
        {
            out = '-';
        }

        putchar(out);

        // Prepare for next day
        if (must_mouse > 0)
            must_mouse--;
        if (no_mouse > 0)
            no_mouse--;

        if (appear)
        {
            if (c == 'X')
            {
                if (no_mouse < 1)
                    no_mouse = 1; // unhappy for next day
            }
            else if (c == 'T')
            {
                if (no_mouse < 2)
                    no_mouse = 2; // sad for next 2 days
                profit += 7;      // +10 reward -3 cheese
            }
            else if (c == 'C')
            {
                if (must_mouse < 2)
                    must_mouse = 2; // excited next 2 days
                profit -= 3;        // cheese cost
            }
        }
    }

    putchar('\n');
    printf("%d\n", profit);
    return 0;
}