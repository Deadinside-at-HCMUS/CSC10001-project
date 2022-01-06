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

void showBooks(Book &book, int &countbooks, int &countquantity);

void addBook(Book &book, int &countbooks);

void modifyBook(Book &book);

void deleteBook(Book &book, int &countbooks);

void findBookByISBN(Book &book);

void findBooksByName(Book &book);

void quantitybooks(int countquantity);

void categorybooks(Book &book);

void checkoutofstock(Book &book);
