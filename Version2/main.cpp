// 21127175
// Lê Anh Thư
// 21CLC07

#include <iostream>
#include "logo.h"
#include "menu.h"
#include "user.h"
#include "book.h"
#include "ticket.h"
#include "day.h"
#define MAX 100

using namespace std;

int main() {
    int option;
    char keepChoosing;

    char choice;
    User user;
    Book book;
    Ticket ticket;
    Today today;
    int countusers, countbooks, countquantity, countrent;

    importLibraryLogo();
    importMainMenu(today);
    cin >> option;

    while (1) {
        switch (option)
        {
            case 0:
                keepChoosing = 0;
                break;
            case 1:
                importBookLogo();
                importUsersMenu();
                cin >> choice;
                cout << endl;

                switch(choice) {
                    case 'a':
                        showUsers(user, countusers);
                        break;
                    case 'b':
                        addUser(user, countusers);
                        break;
                    case 'c':
                        modifyUser(user);
                        break;
                    case 'd':
                        deleteUser(user, countusers);
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
                importBooksLogo();
                importBooksMenu();
                cin >> choice;
                cout << endl;

                switch(choice) {
                    case 'a':
                        showBooks(book, countbooks, countquantity);
                        break;
                    case 'b':
                        addBook(book, countbooks);
                        break;
                    case 'c':
                        modifyBook(book);
                        break;
                    case 'd':
                        deleteBook(book, countbooks);
                        break;
                    case 'e':
//                        findBooksByISBN(book);
                        break;
                    case 'f':
//                        findBooksByName(book);
                        break;
                    default:
                        cout << "Bạn đã nhập sai cú pháp!\n";
                        break;
                }
                keepChoosing = 1;
                break;
            case 3:
                importRentTicketLogo();
                rentTicket(ticket, countrent);
                keepChoosing = 1;
                break;
            case 4:
                importReturnTicketLogo();
                returnTicket(ticket, countrent);
                keepChoosing = 1;
                break;
            case 5:
                importStatisticsLogo();
                importStatisticMenu();
                cin >> choice;
                cout << endl;

                switch(choice) {
                    case 'a':
                        quantitybooks(countquantity);
                        break;
                    case 'b':
//                        categorybooks(book);
                        break;
                    case 'c':
                        quantityusers(countusers);
                        break;
                    case 'd':
//                        sexusers(user);
                        break;
                    case 'e':
                        rentedbooks(countrent);
                        break;
                    case 'f':
//                        checkduedayticket(user, ticket, today);
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

        if (keepChoosing == 0){
            cout << endl;
            cout << "Chúc bạn một ngày tốt lành!" << endl;
            importCloverLogo();
            break;
        }
        else {
            importMainMenu(today);
            cin >> option;
        }
    }

    return 0;
}