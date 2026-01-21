#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "reader.h"
#include "book.h"
#include "borrow.h"
#include "menu.h"
#include "login.h"
#include "file.h"

int main(void)
{
    // 设置控制台编码为UTF-8以支持中文显示
    system("chcp 65001 > nul");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int choice;
    Reader *readerHead = NULL;
    Book *bookHead = NULL;
    Borrow *borrowHead = NULL;

    /* 1. 文件加载 */
    readerHead = loadReaders("readers.dat");
    bookHead = loadBooks("books.dat");
    borrowHead = loadBorrows("borrows.dat");

    /* 2. 登录模块 */
    if (!login())
    {
        printf("登录失败，程序结束。\n");
        return 0;
    }

    /* 3. 主循环 */
    while (1)
    {
        showMenu();
        printf("请选择功能：");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // 图书管理
        {
            int op;
            printf("\n--- 图书管理 ---\n1. 添加 2. 删除 3. 修改 4. 显示\n请选择：");
            scanf("%d", &op);
            char bookId[20];
            switch (op)
            {
            case 1: bookHead = addBook(bookHead); break;
            case 2:
                printf("输入要删除的图书编号："); scanf("%s", bookId);
                bookHead = deleteBook(bookHead, bookId);
                break;
            case 3:
                printf("输入要修改的图书编号："); scanf("%s", bookId);
                modifyBook(bookHead, bookId);
                break;
            case 4: displayBooks(bookHead); break;
            default: printf("无效选择！\n");
            }
            break;
        }
        case 2: // 读者管理
        {
            int op;
            printf("\n--- 读者管理 ---\n1. 添加 2. 删除 3. 显示\n请选择：");
            scanf("%d", &op);
            char cardId[20];
            switch (op)
            {
            case 1: readerHead = addReader(readerHead); break;
            case 2:
                printf("输入要删除的借书证号："); scanf("%s", cardId);
                readerHead = deleteReader(readerHead, cardId);
                break;
            case 3: displayReaders(readerHead); break;
            default: printf("无效选择！\n");
            }
            break;
        }
        case 3: // 借阅管理
        {
            int op;
            printf("\n--- 借阅管理 ---\n1. 借书 2. 还书 3. 显示某读者借阅\n请选择：");
            scanf("%d", &op);
            char cardId[20];
            switch (op)
            {
            case 1: borrowHead = borrowBook(borrowHead, readerHead, bookHead); break;
            case 2: borrowHead = returnBook(borrowHead, readerHead, bookHead); break;
            case 3:
                printf("输入借书证号："); scanf("%s", cardId);
                showBorrowByReader(borrowHead, bookHead, cardId);
                break;
            default: printf("无效选择！\n");
            }
            break;
        }
        case 4: // 查询统计
        {
            int op;
            printf("\n--- 查询统计 ---\n1. 作者查询 2. 出版社查询 3. 某读者借阅查询\n请选择：");
            scanf("%d", &op);
            char key[50];
            switch (op)
            {
            case 1:
                printf("输入作者姓名："); scanf("%s", key);
                searchBooksByAuthor(bookHead, key);
                break;
            case 2:
                printf("输入出版社："); scanf("%s", key);
                searchBooksByPublisher(bookHead, key);
                break;
            case 3:
                printf("输入借书证号："); scanf("%s", key);
                showBorrowByReader(borrowHead, bookHead, key);
                break;
            default: printf("无效选择！\n");
            }
            break;
        }
        case 5: // 排序功能（示例：按书名排序）
        {
            printf("--- 排序功能（示例：按书名） ---\n");
            if (!bookHead) { printf("没有图书数据！\n"); break; }
            Book *i, *j;
            char tmpName[50];
            for (i = bookHead; i; i = i->next)
            {
                for (j = i->next; j; j = j->next)
                {
                    if (strcmp(i->name, j->name) > 0)
                    {
                        // 交换内容
                        Book t = *i;
                        *i = *j;
                        *j = t;
                        i->next = j->next;
                        j->next = j;
                    }
                }
            }
            printf("排序完成（按书名）\n");
            displayBooks(bookHead);
            break;
        }
        case 0: // 退出
            saveReaders("readers.dat", readerHead);
            saveBooks("books.dat", bookHead);
            saveBorrows("borrows.dat", borrowHead);
            printf("系统已退出。\n");
            return 0;
        default:
            printf("无效选择，请重新输入。\n");
        }
    }
}
