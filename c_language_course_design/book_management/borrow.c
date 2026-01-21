#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "borrow.h"

/* 检查读者是否还能借书 */
int canBorrow(Reader *r)
{
    if (strcmp(r->title, "本科生") == 0 && r->borrowCount >= 5)
        return 0;
    if (strcmp(r->title, "研究生") == 0 && r->borrowCount >= 8)
        return 0;
    return 1;
}

/* 借书 */
Borrow* borrowBook(Borrow *bHead, Reader *rHead, Book *bookHead)
{
    char cardId[20], bookId[20];
    printf("输入借书证号：");
    scanf("%s", cardId);
    printf("输入图书编号：");
    scanf("%s", bookId);

    Reader *r = rHead;
    while (r && strcmp(r->cardId, cardId) != 0) r = r->next;
    if (!r) { printf("读者不存在！\n"); return bHead; }

    if (!canBorrow(r)) {
        printf("该读者借书数量已达上限！\n");
        return bHead;
    }

    Book *b = bookHead;
    while (b && strcmp(b->bookId, bookId) != 0) b = b->next;
    if (!b) { printf("图书不存在！\n"); return bHead; }
    if (b->isBorrowed) { printf("该图书已被借出！\n"); return bHead; }

    Borrow *newBorrow = (Borrow*)malloc(sizeof(Borrow));
    strcpy(newBorrow->cardId, cardId);
    strcpy(newBorrow->bookId, bookId);

    printf("输入借书日期（yyyy-mm-dd）：");
    scanf("%s", newBorrow->borrowDate);

    newBorrow->limitDays = (strcmp(b->category, "文学") == 0) ? 30 : 60;

    newBorrow->next = bHead;
    bHead = newBorrow;

    r->borrowCount += 1;
    b->isBorrowed = 1;

    printf("借书成功！借期 %d 天\n", newBorrow->limitDays);
    return bHead;
}

/* 还书 */
Borrow* returnBook(Borrow *bHead, Reader *rHead, Book *bookHead)
{
    char cardId[20], bookId[20];
    printf("输入借书证号：");
    scanf("%s", cardId);
    printf("输入图书编号：");
    scanf("%s", bookId);

    Borrow *prev = NULL, *curr = bHead;
    while (curr)
    {
        if (strcmp(curr->cardId, cardId) == 0 &&
            strcmp(curr->bookId, bookId) == 0)
        {
            if (prev) prev->next = curr->next;
            else bHead = curr->next;

            // 更新读者和图书状态
            Reader *r = rHead;
            while (r && strcmp(r->cardId, cardId) != 0) r = r->next;
            if (r) r->borrowCount -= 1;

            Book *b = bookHead;
            while (b && strcmp(b->bookId, bookId) != 0) b = b->next;
            if (b) b->isBorrowed = 0;

            free(curr);
            printf("还书成功！\n");
            return bHead;
        }
        prev = curr;
        curr = curr->next;
    }

    printf("未找到该借阅记录！\n");
    return bHead;
}

/* 显示某读者所有借阅图书 */
void showBorrowByReader(Borrow *bHead, Book *bookHead, char *cardId)
{
    printf("\n--- 借阅记录 ---\n");
    Borrow *curr = bHead;
    while (curr)
    {
        if (strcmp(curr->cardId, cardId) == 0)
        {
            Book *b = bookHead;
            while (b && strcmp(b->bookId, curr->bookId) != 0) b = b->next;
            if (b)
                printf("%s\t%s\t%s\t鍊熶功鏃ユ湡:%s\t鍊熸湡:%d 澶‐n",
                       b->bookId, b->name, b->author,
                       curr->borrowDate, curr->limitDays);
        }
        curr = curr->next;
    }
}
