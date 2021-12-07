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
    int countusers;
    string id[MAX], cmnd[MAX], nameuser[MAX], birthday[MAX], sex[MAX], email[MAX], address[MAX], createday[MAX], dueday[MAX];
    string isbn[MAX], namebook[MAX], nameauthor[MAX], publishcompany[MAX], category[MAX];
    int publishyear[MAX], price[MAX], quantity[MAX], countbooks;
    string rentuserid[MAX], rentbookid[MAX], rentday[MAX], payday[MAX];
    int countrent;

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
                        showUsers(id, nameuser, cmnd, birthday, sex, email, address, createday, dueday, countusers);
                        break;
                    case 'b':
                        addUser(id, nameuser, cmnd, birthday, sex, email, address, createday, dueday, countusers);
                        break;
                    case 'c':
                        modifyUser(id, nameuser, cmnd, birthday, sex, email, address, createday, dueday, countusers);
                        break;
                    case 'd':
                        deleteUser(id, nameuser, cmnd, birthday, sex, email, address, createday, dueday, countusers);
                        break;
                    case 'e':
                        findUserByCMND(id, nameuser, cmnd, birthday, sex, email, address, createday, dueday, countusers);
                        break;
                    case 'f':
                        findUsersByName(id, nameuser, cmnd, birthday, sex, email, address, createday, dueday, countusers);
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
                        showBooks(isbn, namebook, nameauthor, publishcompany, publishyear, category, price, quantity, countbooks);
                        break;
                    case 'b':
                        addBook(isbn, namebook, nameauthor, publishcompany, publishyear, category, price, quantity, countbooks);
                        break;
                    case 'c':
                        modifyBook(isbn, namebook, nameauthor, publishcompany, publishyear, category, price, quantity, countbooks);
                        break;
                    case 'd':
                        deleteBook(isbn, namebook, nameauthor, publishcompany, publishyear, category, price, quantity, countbooks);
                        break;
                    case 'e':
                        findBooksByISBN(isbn, namebook, nameauthor, publishcompany, publishyear, category, price, quantity, countbooks);
                        break;
                    case 'f':
                        findBooksByName(isbn, namebook, nameauthor, publishcompany, publishyear, category, price, quantity, countbooks);
                        break;
                    default:
                        cout << "Bạn đã nhập sai cú pháp!\n";
                        break;
                }
                keepChoosing = 1;
                break;
            case 3:
                rentTicket(id, countusers, isbn, countbooks, rentuserid, rentbookid, rentday, payday, countrent);
                keepChoosing = 1;
                break;
            case 4:
                cout << "Chức năng '(4) Lập phiếu trả sách'\n";
                keepChoosing = 1;
                break;
            case 5:
                importStatisticMenu();
                cin >> choice;
                cout << endl;

                switch(choice) {
                    case 'a':
                        quantitybooks(quantity, countbooks);
                        break;
                    case 'b':
                        categorybooks(category, quantity, countbooks);
                        break;
                    case 'c':
                        quantityusers(countusers);
                        break;
                    case 'd':
                        sexusers(sex, countusers);
                        break;
                    case 'e':
                        cout << "Chức năng e\n";
                    case 'f':
                        cout << "Chức năng f\n";
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