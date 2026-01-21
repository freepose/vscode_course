
#ifndef FILE_H
#define FILE_H

#include "reader.h"
#include "book.h"     // 鎻愬墠鍖呭惈
#include "borrow.h"

/* 鍑芥暟澹版槑 */
Reader* loadReaders(const char *filename);
void saveReaders(const char *filename, Reader *head);
Book* loadBooks(const char *filename);
void saveBooks(const char *filename, Book *head);
Borrow* loadBorrows(const char *filename);
void saveBorrows(const char *filename, Borrow *head);

#endif

