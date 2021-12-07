#include <iostream>
#include "menu.h"

using namespace std;

void importLogo() {
    cout << " /$$       /$$ /$$                                             \n"
            "| $$      |__/| $$                                             \n"
            "| $$       /$$| $$$$$$$   /$$$$$$  /$$$$$$   /$$$$$$  /$$   /$$\n"
            "| $$      | $$| $$__  $$ /$$__  $$|____  $$ /$$__  $$| $$  | $$\n"
            "| $$      | $$| $$  \\ $$| $$  \\__/ /$$$$$$$| $$  \\__/| $$  | $$\n"
            "| $$      | $$| $$  | $$| $$      /$$__  $$| $$      | $$  | $$\n"
            "| $$$$$$$$| $$| $$$$$$$/| $$     |  $$$$$$$| $$      |  $$$$$$$\n"
            "|________/|__/|_______/ |__/      \\_______/|__/       \\____  $$\n"
            "                                                      /$$  | $$\n"
            "                                                     |  $$$$$$/\n"
            "                                                      \\______/\n";
}

void importMainMenu() {
    cout << endl;
    cout << "====================================================================" << endl;
    cout << "||                    Các chức năng của chương trình              ||" << endl;
    cout << "====================================================================" << endl;
    cout << "|| (1) Quản lí độc giả            ||             (2) Quản lí sách ||" << endl;
    cout << "|| (3) Lập phiếu mượn sách        ||       (4) Lập phiếu trả sách ||" << endl;
    cout << "|| (5) Các thống kế cơ bản        ||       (0) Thoát chương trình ||" << endl;
    cout << "====================================================================" << endl;
    cout << endl;
    cout << "Mời bạn chọn chức năng tương ứng: ";
}

void importUsersMenu() {
    cout << endl;
    cout << "==================================================================================" << endl;
    cout << "||                   Các chức năng trong '(1) Quản lí độc giả'                  ||" << endl;
    cout << "==================================================================================" << endl;
    cout << "|| (a) Xem danh sách độc giả trong thư viện ||                 (b) Thêm độc giả ||" << endl;
    cout << "|| (c) Chỉnh sửa thông tin một độc giả      ||    (d) Xóa thông tin một độc giả ||" << endl;
    cout << "|| (e) Tìm kiếm độc giả theo CMND           ||    (f) Tìm kiếm sách theo họ tên ||" << endl;
    cout << "==================================================================================" << endl;
    cout << endl;
    cout << "Mời bạn chọn chức năng tương ứng: ";
}

void importBooksMenu() {
    cout << endl;
    cout << "==================================================================================" << endl;
    cout << "||                      Các chức năng trong '(2) Quản lí sách'                  ||" << endl;
    cout << "==================================================================================" << endl;
    cout << "|| (a) Xem danh sách các sách trong thư viện ||                   (b) Thêm sách ||" << endl;
    cout << "|| (c) Chỉnh sửa thông tin một quyển sách    ||          (d) Xóa thông tin sách ||" << endl;
    cout << "|| (e) Tìm kiếm sách theo ISBN               || (f) Tìm kiếm sách theo tên sách ||" << endl;
    cout << "==================================================================================" << endl;
    cout << endl;
    cout << "Mời bạn chọn chức năng tương ứng: ";
}

void importStatisticMenu() {
    cout << endl;
    cout << "==============================================================================================" << endl;
    cout << "||                   Các chức năng trong '(5) Các thống kê cơ bản'                          ||" << endl;
    cout << "==============================================================================================" << endl;
    cout << "(a) Thống kê số lượng sách trong thư viện ||       (b) Thống kê số lượng sách theo thể loại ||" << endl;
    cout << "(c) Thống kế số lượng độc giả             ||   (d) Thống kê số lượng độc giả theo giới tính ||" << endl;
    cout << "(e) Thống kê số sách đang được mượn       ||      (f) Thống kê danh sách độc giả bị trễ hạn ||" << endl;
    cout << "==============================================================================================" << endl;
    cout << endl;
    cout << "Mời bạn chọn chức năng tương ứng: ";
}