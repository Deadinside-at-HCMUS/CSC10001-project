#pragma once

#include "user.h"
#include "book.h"
#include "day.h"
#define MAX 100

using namespace std;

int leapYear(int year);

int dayInMonth(int month, int year);

struct Ticket {
    char rentuserid[MAX];
    char rentbookid[MAX];
    char rentid[MAX];
    char rentday[MAX];
    char payday[MAX];
};

void rentTicket(Ticket &ticket, int &countrent);

void returnTicket(Ticket &ticket, int &countrent);

void rentedbooks(int &countrent);

void checkduedayticket(Ticket &ticket, Today today);