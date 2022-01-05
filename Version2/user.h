#pragma once

#include "day.h"
#define MAX 100

using namespace std;

struct User {
    char id[MAX];
    char nameuser[MAX];
    char cmnd[MAX];
    char birthday[MAX];
    char sex[MAX];
    char email[MAX];
    char address[MAX];
    char createday[MAX];
    char dueday[MAX];
};

void showUsers(User user, int &countusers);

void addUser(User &user, int &countusers);

void modifyUser(User &user, int &countusers);

void deleteUser(User &user);

void findUserByCMND(User &user);

void findUsersByName(User &user);

void quantityusers(int countusers);

void sexusers(User &user);

void checkduedayuser(User &user, Today today);