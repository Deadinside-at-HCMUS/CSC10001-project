#pragma once

#include <iostream>
#define MAX 100

using namespace std;

struct Book {
    string isbn[MAX];
    string namebook[MAX];
    string nameauthor[MAX];
    string publishcompany[MAX];
    int publishyear[MAX];
    string category[MAX];
    int price[MAX];
    int quantity[MAX];
    int countbooks;
};

void showBooks(Book &book);

void addBook(Book &book);

void modifyBook(Book &book);

void deleteBook(Book &book);

void findBooksByISBN(Book &book);

void findBooksByName(Book &book);

void quantitybooks(Book &book);

void categorybooks(Book &book);
