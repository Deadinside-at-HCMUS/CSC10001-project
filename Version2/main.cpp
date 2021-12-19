// 21127175
// Lê Anh Thư
// 21CLC07

#include <iostream>
#include "menu.h"
#include "user.h"
#include "book.h"
#include "ticket.h"
#define MAX 100

using namespace std;

int main() {
    int option;
    char keepChoosing;
    importLogo();
    importMainMenu();
    cin >> option;

    char choice;
    User user;
    Book book;
    Ticket ticket;
    string today;

    while (1) {
        switch (option)
        {
            case 0:
                keepChoosing = 0;
                break;
            case 1:
                importUsersMenu();
                cin >> choice;
                cout << endl;

                switch(choice) {
                    case 'a':
                        showUsers(user);
                        break;
                    case 'b':
                        addUser(user);
                        break;
                    case 'c':
                        modifyUser(user);
                        break;
                    case 'd':
                        deleteUser(user);
                        break;
                    case 'e':
                        findUserByCMND(user);
                        break;
                    case 'f':
                        findUsersByName(user);
                        break;
                    default:
                        cout << "Bạn đã nhập sai cú pháp!\n";
                        break;
                }
                keepChoosing = 1;
                break;
            case 2:
                importBooksMenu();
                cin >> choice;
                cout << endl;

                switch(choice) {
                    case 'a':
                        showBooks(book);
                        break;
                    case 'b':
                        addBook(book);
                        break;
                    case 'c':
                        modifyBook(book);
                        break;
                    case 'd':
                        deleteBook(book);
                        break;
                    case 'e':
                        findBooksByISBN(book);
                        break;
                    case 'f':
                        findBooksByName(book);
                        break;
                    default:
                        cout << "Bạn đã nhập sai cú pháp!\n";
                        break;
                }
                keepChoosing = 1;
                break;
            case 3:
                rentTicket(user, book, ticket);
                keepChoosing = 1;
                break;
            case 4:
                returnTicket(ticket, today);
                keepChoosing = 1;
                break;
            case 5:
                importStatisticMenu();
                cin >> choice;
                cout << endl;

                switch(choice) {
                    case 'a':
                        quantitybooks(book);
                        break;
                    case 'b':
                        categorybooks(book);
                        break;
                    case 'c':
                        quantityusers(user);
                        break;
                    case 'd':
                        sexusers(user);
                        break;
                    case 'e':
                        rentedbooks(ticket);
                        break;
                    case 'f':
                        checkdueday(user, ticket, today);
                        break;
                    default:
                        cout << "Bạn đã nhập sai cú pháp!\n";
                        break;
                }
                keepChoosing = 1;
                break;
            default:
                cout << "Bạn đã nhập sai cú pháp!\n";
                break;
        }

        if (keepChoosing == 0) break;
        else {
            importMainMenu();
            cin >> option;
        }
    }

    return 0;
}