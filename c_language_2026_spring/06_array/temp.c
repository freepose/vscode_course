#include <stdio.h>

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int find_max(int arr[], int size)
{
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[index] < arr[i])
        {
            index = i;
        }
    }
    return index;
}

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int index = i; 
        for (int j = i + 1; j < size; j++)
        {
            if (arr[index] > arr[j])
            {
                index = j;
            }
        }

        if (index != i)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}

void bubble_sort(int arr[], int size)
{
    /// @param arr 待排序数组
    /// @param size 数组大小
    
    for (int i = 0; i < size - 1; i++)
    {
        // 先尝试相邻两两比较
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int scores[10] = {67, 88, 76, 90, 56, 95, 72, 83, 80, 92};
    int i;

    print_array(scores, 10);

    // selection_sort(scores, 10);
    bubble_sort(scores, 10);

    print_array(scores, 10);

    return 0;
}
