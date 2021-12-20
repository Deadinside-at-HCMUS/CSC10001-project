#pragma once

#include <iostream>
#define MAX 100

using namespace std;


void showUsers(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers);

void addUser(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers);

void modifyUser(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers);

void deleteUser(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers);

void findUserByCMND(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers);

void findUsersByName(
        string id[MAX],
        string nameuser[MAX],
        string cmnd[MAX],
        string birthday[MAX],
        string sex[MAX],
        string email[MAX],
        string address[MAX],
        string createday[MAX],
        string dueday[MAX],
        int &countusers);

void quantityusers(int &countusers);

void sexusers(string sex[MAX], int &countusers);

void checkduedayuser(string id[MAX], string nameuser[MAX], string dueday[MAX], int &countusers);