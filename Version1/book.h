#pragma once

#define MAX 100

using namespace std;

void showBooks(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks);

void addBook(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks);

void modifyBook(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks);

void deleteBook(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks);

void findBooksByISBN(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks);

void findBooksByName(
        string isbn[MAX],
        string namebook[MAX],
        string nameauthor[MAX],
        string publishcompany[MAX],
        int publishyear[MAX],
        string category[MAX],
        int price[MAX],
        int quantity[MAX],
        int &countbooks);

void quantitybooks(int quantity[MAX], int &countbooks);

void categorybooks(string category[MAX], int quantity[MAX], int &countbooks);
