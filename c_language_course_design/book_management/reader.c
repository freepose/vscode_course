#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

/* 添加读者 */
Reader* addReader(Reader *head)
{
    Reader *p = (Reader*)malloc(sizeof(Reader));
    if (!p) {
        printf("内存分配失败！\n");
        return head;
    }

    printf("输入借书证号：");
    scanf("%s", p->cardId);
    printf("姓名：");
    scanf("%s", p->name);
    printf("单位：");
    scanf("%s", p->unit);
    printf("性别：");
    scanf("%s", p->gender);
    printf("职称（本科生/研究生）：");
    scanf("%s", p->title);
    printf("地址：");
    scanf("%s", p->address);

    p->borrowCount = 0;
    p->next = head;
    head = p;

    printf("读者添加成功！\n");
    return head;
}

/* 鏄剧ず鎵€鏈夎鑰?*/
void displayReaders(Reader *head)
{
    printf("\n--- 璇昏€呭垪琛?---\n");
    while (head)
    {
        printf("%s\t%s\t%s\t%s\t%s\t鍊熶功鏁伴噺:%d\n",
               head->cardId, head->name, head->unit,
               head->gender, head->title, head->borrowCount);
        head = head->next;
    }
}

/* 鍒犻櫎璇昏€?*/
Reader* deleteReader(Reader *head, char *cardId)
{
    Reader *prev = NULL, *curr = head;
    while (curr)
    {
        if (strcmp(curr->cardId, cardId) == 0)
        {
            if (prev) prev->next = curr->next;
            else head = curr->next;

            free(curr);
            printf("璇昏€呭垹闄ゆ垚鍔燂紒\n");
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("鏈壘鍒拌璇昏€咃紒\n");
    return head;
}

/* 淇敼璇昏€?*/
void modifyReader(Reader *head, char *cardId)
{
    Reader *r = head;
    while (r)
    {
        if (strcmp(r->cardId, cardId) == 0)
        {
            printf("淇敼濮撳悕锛堝綋鍓嶏細%s锛夛細", r->name); scanf("%s", r->name);
            printf("淇敼鍗曚綅锛堝綋鍓嶏細%s锛夛細", r->unit); scanf("%s", r->unit);
            printf("淇敼鎬у埆锛堝綋鍓嶏細%s锛夛細", r->gender); scanf("%s", r->gender);
            printf("淇敼鑱岀О锛堝綋鍓嶏細%s锛夛細", r->title); scanf("%s", r->title);
            printf("淇敼鍦板潃锛堝綋鍓嶏細%s锛夛細", r->address); scanf("%s", r->address);

            printf("淇敼鎴愬姛锛乗n");
            return;
        }
        r = r->next;
    }
    printf("鏈壘鍒拌璇昏€咃紒\n");
}

/* 鏌ユ壘璇昏€?*/
Reader* findReaderByCard(Reader *head, char *cardId)
{
    while (head)
    {
        if (strcmp(head->cardId, cardId) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}
