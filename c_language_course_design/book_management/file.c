
#include <stdlib.h>
#include "file.h"
#include "book.h"   // 一定要包含
#include "reader.h"
#include "borrow.h"
#include <stdio.h>
#include <string.h>


/* ----------------- 读者数据 ----------------- */

/* 读取读者数据 */
Reader* loadReaders(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    Reader *head = NULL, *p;
    while (1)
    {
        p = (Reader*)malloc(sizeof(Reader));
        if (!p) { printf("内存分配失败！\n"); break; }

        if (fread(p, sizeof(Reader), 1, fp) != 1) {
            free(p);
            break;
        }

        p->next = head;
        head = p;
    }

    fclose(fp);
    return head;
}

/* 保存读者数据 */
void saveReaders(const char *filename, Reader *head)
{
    FILE *fp = fopen(filename, "wb");
    if (!fp) { printf("文件打开失败！\n"); return; }

    while (head)
    {
        fwrite(head, sizeof(Reader), 1, fp);
        head = head->next;
    }

    fclose(fp);
}

/* ----------------- 图书数据 ----------------- */

Book* loadBooks(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    Book *head = NULL, *p;
    while (1)
    {
        p = (Book*)malloc(sizeof(Book));
        if (!p) { printf("内存分配失败！\n"); break; }

        if (fread(p, sizeof(Book), 1, fp) != 1) {
            free(p);
            break;
        }

        p->next = head;
        head = p;
    }

    fclose(fp);
    return head;
}

void saveBooks(const char *filename, Book *head)
{
    FILE *fp = fopen(filename, "wb");
    if (!fp) { printf("文件打开失败！\n"); return; }

    while (head)
    {
        fwrite(head, sizeof(Book), 1, fp);
        head = head->next;
    }

    fclose(fp);
}

/* ----------------- 借阅数据 ----------------- */

Borrow* loadBorrows(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    Borrow *head = NULL, *p;
    while (1)
    {
        p = (Borrow*)malloc(sizeof(Borrow));
        if (!p) { printf("内存分配失败！\n"); break; }

        if (fread(p, sizeof(Borrow), 1, fp) != 1) {
            free(p);
            break;
        }

        p->next = head;
        head = p;
    }

    fclose(fp);
    return head;
}

void saveBorrows(const char *filename, Borrow *head)
{
    FILE *fp = fopen(filename, "wb");
    if (!fp) { printf("文件打开失败！\n"); return; }

    while (head)
    {
        fwrite(head, sizeof(Borrow), 1, fp);
        head = head->next;
    }

    fclose(fp);
}
