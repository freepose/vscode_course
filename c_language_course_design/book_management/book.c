#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

/* 校验图书编号规则：TST-2024-001 */
int checkBookId(char *bookId)
{
    // 简单校验前4个字符是 TST-
    if (strncmp(bookId, "TST-", 4) != 0) return 0;
    return 1;
}

/* 获取借阅天数：文学 30天，专业 60天 */
int getLimitDays(Book *b)
{
    if (strcmp(b->category, "文学") == 0)
        return 30;
    else
        return 60;
}

/* 添加图书 */
Book* addBook(Book *head)
{
    Book *p = (Book*)malloc(sizeof(Book));
    if (!p) { printf("内存分配失败！\n"); return head; }

    printf("输入图书编号（TST-xxxx-xxx）：");
    scanf("%s", p->bookId);
    if (!checkBookId(p->bookId))
    {
        printf("图书编号格式错误！\n");
        free(p);
        return head;
    }

    printf("书名："); scanf("%s", p->name);
    printf("作者："); scanf("%s", p->author);
    printf("出版社："); scanf("%s", p->publisher);
    printf("类别（文学/专业）："); scanf("%s", p->category);

    p->isBorrowed = 0;
    p->next = head;
    head = p;

    printf("图书添加成功！\n");
    return head;
}

/* 删除图书 */
Book* deleteBook(Book *head, char *bookId)
{
    Book *prev = NULL, *curr = head;
    while (curr)
    {
        if (strcmp(curr->bookId, bookId) == 0)
        {
            if (prev) prev->next = curr->next;
            else head = curr->next;

            free(curr);
            printf("图书删除成功！\n");
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("未找到该图书！\n");
    return head;
}

/* 修改图书 */
void modifyBook(Book *head, char *bookId)
{
    Book *b = head;
    while (b)
    {
        if (strcmp(b->bookId, bookId) == 0)
        {
            printf("修改书名（当前：%s）：", b->name); scanf("%s", b->name);
            printf("修改作者（当前：%s）：", b->author); scanf("%s", b->author);
            printf("修改出版社（当前：%s）：", b->publisher); scanf("%s", b->publisher);
            printf("修改类别（文学/专业 当前：%s）：", b->category); scanf("%s", b->category);

            printf("修改成功！\n");
            return;
        }
        b = b->next;
    }
    printf("未找到该图书！\n");
}

/* 显示所有图书 */
void displayBooks(Book *head)
{
    printf("\n--- 图书列表 ---\n");
    while (head)
    {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n",
               head->bookId, head->name, head->author,
               head->publisher, head->category,
               head->isBorrowed ? "已借出" : "未借出");
        head = head->next;
    }
}

/* 查找图书 */
Book* findBook(Book *head, char *bookId)
{
    while (head)
    {
        if (strcmp(head->bookId, bookId) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

/* 按作者查询图书 */
void searchBooksByAuthor(Book *head, char *author)
{
    printf("\n--- 按作者查询结果 ---\n");
    while (head)
    {
        if (strcmp(head->author, author) == 0)
        {
            printf("%s\t%s\t%s\t%s\t%s\t%s\n",
                   head->bookId, head->name, head->author,
                   head->publisher, head->category,
                   head->isBorrowed ? "已借出" : "未借出");
        }
        head = head->next;
    }
}

/* 按出版社查询图书 */
void searchBooksByPublisher(Book *head, char *publisher)
{
    printf("\n--- 按出版社查询结果 ---\n");
    while (head)
    {
        if (strcmp(head->publisher, publisher) == 0)
        {
            printf("%s\t%s\t%s\t%s\t%s\t%s\n",
                   head->bookId, head->name, head->author,
                   head->publisher, head->category,
                   head->isBorrowed ? "已借出" : "未借出");
        }
        head = head->next;
    }
}
