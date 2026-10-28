
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createList()
{
    Node *head = (Node *)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("内存分配失败！\n");
        return NULL;
    }

    head->next = NULL;

    return head;
}

void insertHead(Node *head, int value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("内存分配失败！\n");
        return;
    }

    p->next = head->next;
    head->next = p;
}

void insertTail(Node *head, int value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("内存分配失败！\n");
        return;
    }
    p->data = value;
    p->next = NULL;

    Node *pre = head;
    while (pre->next != NULL)
    {
        pre = pre->next;
    }

    pre->next = p;
}

int findData(Node *head, int value)
{
    Node *p = head;

    while (p->next != NULL && p->data != value)
    {
        p = p->next;
    }

    if (p->data == value)
        return 1;
    else
        return 0;
}

int changeData(Node *head, int i, int newdata)
{
    if (head == NULL)
        return 0;

    Node *p = head;
    for (int k = 1; k <= i; k++)
    {
        if (p == NULL)
            return 0;

        p = p->next;
    }

    if (p == NULL)
        return 0;

    p->data = newdata;
    return 1;
}

int deleteNode(Node *head, int value)
{ // 删除指定数据
    Node *pre = head;

    while (pre->next != NULL && pre->next->data != value)
    { // 获取指定数据的前驱
    }

    if (pre->next->data != value)
        return 0;

    Node *target = pre->next;

    pre->next = target->next;

    free(target); // 节点你自由了
    return 1;     // 删除成功
}

void printList(Node *head)
{
    Node *p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    Node *head = createList();

    insertTail(head, 3);
    insertTail(head, 4);
    insertTail(head, 1);
    insertTail(head, 5);

    printf("初始化:");
    printList(head);

    printf("尾插6  :");
    insertTail(head, 6);
    printList(head);

    printf("删除3 :");
    deleteNode(head, 3);
    printList(head);

    printf("更改第二个节点数据为8  :");
    changeData(head, 2, 8);
    printList(head);

    printf("查找5(1真 0假): %d\n", findData(head, 5));
    printf("查找9(1真 0假): %d\n", findData(head, 9));
}
