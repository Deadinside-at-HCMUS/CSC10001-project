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
        int &countrent,
        string returnday[MAX]);