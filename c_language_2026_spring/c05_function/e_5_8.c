
// Example 5-8: This program implements a financial cash accounting system using functions.
// It first takes the operation type (1 for income, 2 for expenditure, 0 to end) as input, then takes the operation amount as input, and calculates the remaining cash balance. The program allows multiple operations until the operation type of 0 is entered to end the program. It requires defining and calling functions, with separate functions for cash income and cash expenditure.

#include <stdio.h>

double balance;

void income(double cash);

void expend(double cash);

int main(void)
{
    int choice;
    double cash;
    cash = 0;
    
    printf("Enter operate choice(0--end, 1--income, 2--expend):");
    scanf("%d", &choice);
    while (choice != 0)
    {
        if (choice == 1 || choice == 2)
        {
            printf("Enter cash:");
            scanf("%lf", &cash);
            if (choice == 1)
            {
                income(cash);
            }
            else
            {
                expend(cash);
            }
            printf("balance:%.2f\n", balance);
        }
        printf("Enter operate choice(0--end, 1--income, 2--expend):");
        scanf("%d", &choice);
    }

    return 0;
}

void income(double cash)
{
    balance = balance + cash;
}

void expend(double cash)
{
    balance = balance - cash;
}

// Enter operate choice(0--end, 1--income, 2--expend):1
// Enter cash:1000
// balance:1000.00
// Enter operate choice(0--end, 1--income, 2--expend):2
// Enter cash:456
// balance:544.00
// Enter operate choice(0--end, 1--income, 2--expend):0