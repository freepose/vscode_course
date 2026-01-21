#ifndef BORROW_H
#define BORROW_H

#include "reader.h"
#include "book.h"

typedef struct Borrow {
    char cardId[20];     // 鍊熶功璇佸彿
    char bookId[20];     // 鍥句功缂栧彿
    char borrowDate[20]; // 鍊熶功鏃ユ湡 yyyy-mm-dd
    int limitDays;       // 鍊熼槄澶╂暟
    struct Borrow *next;
} Borrow;

/* 鍔熻兘鍑芥暟澹版槑 */
Borrow* borrowBook(Borrow *bHead, Reader *rHead, Book *bookHead);
Borrow* returnBook(Borrow *bHead, Reader *rHead, Book *bookHead);
void showBorrowByReader(Borrow *bHead, Book *bookHead, char *cardId);
int canBorrow(Reader *r);

#endif
