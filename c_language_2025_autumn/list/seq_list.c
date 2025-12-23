
// 线性表之一：顺序表

#include <stdio.h>
#include <string.h>

typedef struct _student
{
    char name[50];
    int age;
    float score;
} Student;

typedef struct _seq_list
{
    Student data[100];
    int length;
} SeqList;


void init_seq_list(SeqList* list)
{
    memset(list, 0, sizeof(SeqList));
}

void create_seq_list(SeqList* list, Student arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        list->data[i] = arr[i];
    }
    list->length = n;
}

void delete_element(SeqList* list, int index)
{
    if (index < 0 || index >= list->length)
    {
        return;
    }

    for (int i = index; i < list->length - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->length--;
}

void append_element(SeqList* list, Student element)
{
    if (list->length >= 100)
    {
        return;
    }

    list->data[list->length] = element;
    list->length++;
}

int main()
{
    SeqList student_list;

    init_seq_list(&student_list);

    return 0;
}

