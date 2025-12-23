
// 线性表之二：链表

#include <stdio.h>
#include <stdlib.h>

struct _node
{
    int data;
    struct _node* next;
};

typedef struct _node Node;


Node* create_linked_list(int arr[], int n)
{
    // 头插法
    Node *head = 0;
    Node *p = 0;

    for (int i = 0; i < n; i++)
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = arr[i];

        p->next = head;
        head = p;
    }

    return head;
}

Node *create_linked_list_tail(int arr[], int n)
{
    // 尾插法
    Node *head = 0;
    Node *tail = 0;
    Node *p = 0;

    for (int i = 0; i < n; i++)
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = arr[i];
        p->next = 0;

        if (head == 0)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }

    return head;
}

void print_linked_list(Node* head)
{
    Node* p = head;
    while (p != 0)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void insert_element(Node** head, int index, int value)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = value;

    if (index == 0)
    {
        p->next = *head;
        *head = p;
        return;
    }

    Node* curr = *head;
    for (int i = 0; i < index - 1 && curr != 0; i++)
    {
        curr = curr->next;
    }

    if (curr == 0)
    {
        free(p);
        return;
    }

    p->next = curr->next;
    curr->next = p;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = 0;

    // head = create_linked_list(arr, 5);
    head = create_linked_list_tail(arr, 5);
    print_linked_list(head);

    insert_element(&head, 2, 99);
    print_linked_list(head);

    return 0;
}