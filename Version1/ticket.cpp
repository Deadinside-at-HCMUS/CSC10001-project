#include <iostream>
#include "ticket.h"
#include "book.h"
#include "user.h"
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
        int &countrent ) {
        string rentusercheck;
        string rentbookcheck;
        bool checkuserid = false;
        bool checkbookid = false;
        cout << endl;
        cout << "Lập phiếu mượn sách cho độc giả" << endl;
        cout << endl;
        cin.ignore();
        cout << "Mời nhập mã độc giả cần mượn sách: "; getline(cin, rentusercheck);
        for (int i = 0; i < countusers; i++) {
            if (rentusercheck == id[i]) {
                rentuserid[countrent] = rentusercheck;
                checkuserid = true;
            }
        }
        if (!checkuserid)
            cout << "Mã độc giả không tồn tại!" << endl;
        else {
            cout << "Mời nhập mã sách cần mượn: "; getline(cin, rentbookcheck);
            for (int i = 0; i < countbooks; i++) {
                if (rentbookcheck == isbn[i]) {
                    rentbookid[countrent] = rentbookcheck;
                    checkbookid = true;
                }
            }
            if (!checkbookid)
                cout << "Mã sách không tồn tại!" << endl;
            else {
                cout << "Mời nhập ngày mượn: "; getline(cin, rentday[countrent]);
                cout << "Mời nhập ngày trả dự kiến: "; getline(cin, payday[countrent]);
                countrent++;
                cout << endl;
                cout << "Độc giả mượn sách thành công!" << endl;
            }
        }
};

void payTicket();