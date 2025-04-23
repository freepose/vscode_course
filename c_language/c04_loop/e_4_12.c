
// Example 4-12: Coin Change Problem.
// There are enough coins of 5 cents, 2 cents, and 1 cent. Now we want to use these coins to pay a small amount of change less than 1 yuan, called money. The program asks for the minimum number of coins used. Input the change and output the total number of coins and the number of coins of the corresponding denomination.

#include <stdio.h>

int main(void)
{
    int flag, money, n1, n2, n5;

    flag = 1;
    printf("Enter money: ");
    scanf("%d", &money);
    for (n5 = money / 5; (n5 >= 0) && (flag == 1); n5--)
    {
        for (n2 = (money - n5 * 5) / 2; (n2 >= 0) && (flag == 1); n2--)
        {
            for (n1 = money - n5 * 5 - n2 * 2; (n1 >= 0) && (flag == 1); n1--)
            {
                if ((n5 * 5 + n2 * 2 + n1) == money)
                {
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", n5, n2, n1, n1 + n2 + n5);
                    flag = 0;
                }
            }
        }
    }

    return 0;
}

// Enter money: 12
// fen5:2, fen2:1, fen1:0, total:3