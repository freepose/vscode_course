
// Example 10-1: Operations of ordered table for insertion, deletion, and query. First, input an ordered table with no duplicate elements arranged in ascending order, and display the following menu (number and option) on the screen. The user can repeatedly perform insertion, deletion, and query operations on this ordered table, or choose to end. When the user inputs numbers 1-3 and related parameters, the ordered table will be respectively inserted, deleted, and queried. Inputting other numbers will end the operation.

#include <stdio.h>

#define MAXN 100

int Count = 0;

void select(int a[], int option, int value);

int input_array(int a[]);

void print_array(int a[]);

void insert(int a[], int value);

// In the text book, the function name is remove, but it is a keyword in C language, so here changed it to delete_element.

void delete_element(int a[], int value);

void query(int a[], int value);

int main(void)
{
    int option, value, a[MAXN];

    if (input_array(a) == -1)
    {
        return 0;
    }
    printf("[1] Insert\n");
    printf("[2] Delete\n");
    printf("[3] Query\n");
    printf("[Other option] End\n");
    while (1)
    {
        printf("Input option: ");
        scanf("%d", &option);
        if (option < 1 || option > 3)
        {
            break;
        }
        printf("Input an element: ");
        scanf("%d", &value);
        select(a, option, value);
        printf("\n");
    }
    printf("Thanks.");
    return 0;
}

void select(int a[], int option, int value)
{
    switch (option)
    {
    case 1:
        insert(a, value);
        break;
    case 2:
        delete_element(a, value);
        break;
    case 3:
        query(a, value);
        break;
    }
}

int input_array(int a[])
{
    printf("Input the number of array elements: ");
    scanf("%d", &Count);
    printf("Input an ordered array element: ");
    for (int i = 0; i < Count; i++)
    {
        scanf("%d", &a[i]);
        if (i > 0 && a[i] <= a[i - 1])
        {
            printf("Error");
            return -1;
        }
    }
    return 0;
}

void print_array(int a[])
{
    printf("The ordered array a is: ");
    for (int i = 0; i < Count; i++)
    {
        if (i == 0)
        {
            printf("%d", a[i]);
        }
        else
        {
            printf(" %d", a[i]);
        }
    }
}

void insert(int a[], int value)
{
    int i, j;

    for (i = 0; i < Count; i++)
    {
        if (value < a[i])
        {
            break;
        }
    }
    for (j = Count - 1; j >= i; j--)
    {
        a[j + 1] = a[j];
    }
    a[i] = value;
    Count++;
    print_array(a);
}

void delete_element(int a[], int value)
{
    int i, index = -1;

    for (i = 0; i < Count; i++)
    {
        if (value == a[i])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Failed to find the data, deletion failed.");
        return;
    }
    else
    {
        for (i = index; i < Count - 1; i++)
        {
            a[i] = a[i + 1];
        }
        Count--;
        print_array(a);
    }
}

void query(int a[], int value)
{
    int mid, left = 0, right = Count - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (value == a[mid])
        {
            printf("The index is: %d", mid);
            return;
        }
        else if (value < a[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    printf("This element does not exist.");
}

// Input the number of array elements: 6
// Input an ordered array element: -2 3 7 9 101 400
// [1] Insert
// [2] Delete
// [3] Query
// [Other option] End
// Input option: 1
// Input an element: 0
// The ordered array a is: -2 0 3 7 9 101 400
// Input option: 3  
// Input an element: 101
// The index is: 5
// Input option: 9
// Thanks.