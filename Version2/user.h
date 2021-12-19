#pragma once

#include <iostream>
#define MAX 100

using namespace std;

struct User {
    string id[MAX];
    string nameuser[MAX];
    string cmnd[MAX];
    string birthday[MAX];
    string sex[MAX];
    string email[MAX];
    string address[MAX];
    string createday[MAX];
    string dueday[MAX];
    int countusers;
};

void showUsers(User &user);

void addUser(User &user);

void modifyUser(User &user);

void deleteUser(User &user);

void findUserByCMND(User &user);

void findUsersByName(User &user);

void quantityusers(User &user);

void sexusers(User &user);