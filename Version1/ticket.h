#pragma once

#define MAX 100

using namespace std;

int leapYear(int year);

int dayInMonth(int month, int year);

int dayToNum(int d, int m, int y);

void rentTicket(
        string id[MAX],
        int &countusers,
        string isbn[MAX],
        int price[MAX],
        int &countbooks,
        string rentuserid[MAX],
        string rentbookid[MAX],
        string rentday[MAX],
        string payday[MAX],
        string rentid[MAX],
        int pricerent[MAX],
        int &countrent);

void returnTicket(
        string rentuserid[MAX],
        string rentbookid[MAX],
        string rentday[MAX],
        string payday[MAX],
        string rentid[MAX],
        int pricerent[MAX],
        int &countrent);

void rentedbooks(int &countrent);

void checkduedayticket(
        string id[MAX],
        string nameuser[MAX],
        string rentuserid[MAX],
        int &countuser,
        string payday[MAX],
        int &countrent);