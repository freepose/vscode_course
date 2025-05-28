
// Example 8-6: using pointers to count array elements

#include <stdio.h>

void print_array(int *array, int size)
{
    // array is a pointer to the first element of the array

    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int sum_array(int *array, int size)
{
    // array is a pointer to the first element of the array

    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

int main()
{
    int a[10] = {55, 23, 8, 11, 22, 89, 0, -1, 78, 186};

    int *p = &a[0]; // int *p = a; 
    int *q = &a[9];

    printf("*p = %d\n", *p);
    printf("*q = %d\n", *q);

    printf("p - q = %d\n", q - p);  // 相差的元素个数

    printf("*(p+1) = %d\n", *(p + 1));

    printf("sum of array[1] ... arry[8] = %d\n", sum_array(&a[1], 8)); 

    return 0;
}