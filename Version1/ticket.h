#pragma once

#include <iostream>
#define MAX 100

using namespace std;

void rentTicket(
        string id[MAX],
        int &countusers,
        string isbn[MAX],
        int &countbooks,
        string rentuserid[MAX],
        string rentbookid[MAX],
        string rentday[MAX],
        string payday[MAX],
        string rentid[MAX],
        int &countrent);

void returnTicket(
        string rentuserid[MAX],
        string rentbookid[MAX],
        string rentday[MAX],
        string payday[MAX],
        string rentid[MAX],
        int &countrent);

void rentedbooks(int &countrent);

void checkdueday(string id[MAX], string nameuser[MAX], string rentuserid[MAX], int &countuser, string payday[MAX], int &countrent, string today);