#pragma once

#include "user.h"
#include "book.h"
#include "day.h"
#define MAX 100

using namespace std;

int leapYear(int year);

int dayInMonth(int month, int year);

int dayToNum(int d, int m, int y);

struct Ticket {
    string rentuserid[MAX];
    string rentbookid[MAX];
    string rentday[MAX];
    string payday[MAX];
    string rentid[MAX];
    int pricerent[MAX];
    int countrent;
};

void rentTicket(User &user, Book &book, Ticket &ticket);

void returnTicket(User &user, Book &book, Ticket &ticket, Today today);

void rentedbooks(Ticket &ticket);

void checkduedayticket(User &user, Ticket &ticket, Today today);