
// Example 3-8: Query the price of goods in a vending machine. 
// [1] select crisps: 3.0
// [2] select popcorn: 2.5
// [3] select chocolate: 4.0
// [4] select cola: 3.5
// [0] exit, can exit at any time, and will exit automatically after 5 times.

#include <stdio.h>

int main()
{
    int choice, i;
    double price;

    printf("[1] Select crisps\n");    
    printf("[2] Select popcorn\n");   
    printf("[3] Select chocolate\n");
    printf("[4] Select cola\n");     
    printf("[0] exit \n");         

    for (i = 1; i <= 5; i++)
    {                           
        printf("Enter choice: "); 
        scanf("%d", &choice);    

        if (choice == 0)
        {
            break; 
        }
      
        switch (choice)
        {
        case 1:
            price = 3.0;
            break; 
        case 2:
            price = 2.5;
            break;
        case 3:
            price = 4.0;
            break;
        case 4:
            price = 3.5;
            break;
        default:
            price = 0.0;
            break;
        }

        printf("price = %0.1f\n", price);
    } 
    printf("Thanks\n");

    return 0;
}
