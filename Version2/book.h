#pragma once

#define MAX 100

using namespace std;

struct Book {
    char isbn[MAX];
    char namebook[MAX];
    char nameauthor[MAX];
    char publishcompany[MAX];
    char publishyear[MAX];
    char category[MAX];
    char price[MAX];
    char quantity[MAX];
};

void showBooks(Book &book, int &countbooks);

void addBook(Book &book, int countbooks);

void modifyBook(Book &book);

void deleteBook(Book &book);

void findBooksByISBN(Book &book);

void findBooksByName(Book &book);

void quantitybooks(Book &book, int countbooks);

void categorybooks(Book &book);

void checkoutofstock(Book &book);
