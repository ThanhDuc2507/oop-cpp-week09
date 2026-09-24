#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <ctime>

using namespace std;

struct Order {
    string code;
    string customerName;
    string phone;
    string dish;
    int quantity;
    string status;
    string address;
};

vector<string> menuDishes = {
    "Banh mi",
    "Pho bo",
    "Com tam",
    "Bun bo",
    "Hamburger",
    "Pizza",
    "Tra sua"
};

vector<Order> orders = {
    {"AN2026001", "Nguyen Van An", "0901234567", "Banh mi", 2, "Dang chuan bi", "123 Nguyen Trai, Quan 1, TP.HCM"},
    {"BIN2026002", "Tran Thi Binh", "0912345678", "Pho bo", 1, "Dang giao", "456 Le Loi, Quan 1, TP.HCM"},
    {"CUO2026003", "Le Van Cuong", "0987654321", "Banh mi", 3, "Hoan thanh", "789 Cach Mang Thang 8, Quan 10, TP.HCM"}
};

// =========================
// BAI 1
// Nhap va hien thi ten cua hang
// =========================
void bai1() {
    string shopName;

    cout << "\n===== BAI 1: TEN CUA HANG =====\n";
    cout << "Nhap ten cua hang: ";
    getline(cin, shopName);

    cout << "Chao mung den voi [" << shopName << "]!\n";
}

// =========================
// BAI 2
// Chuan hoa ten mon an
// =========================
string trim(string s) {
    while (!s.empty() && s.front() == ' ')
        s.erase(s.begin());

    while (!s.empty() && s.back() == ' ')
        s.pop_back();

    return s;
}

string normalizeDishName(string s) {
    s = trim(s);

    bool newWord = true;

    for (int i = 0; i < (int)s.length(); i++) {
        if (s[i] == ' ') {
            newWord = true;
        }
        else {
            if (newWord && s[i] >= 'a' && s[i] <= 'z') {
                s[i] = toupper(s[i]);
            }
            else if (!newWord && s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
            }

            newWord = false;
        }
    }

    return s;
}

void bai2() {
    string dish;

    cout << "\n===== BAI 2: CHUAN HOA TEN MON AN =====\n";
    cout << "Nhap ten mon an: ";
    getline(cin, dish);

    cout << "Ten mon sau khi chuan hoa: "
         << normalizeDishName(dish) << endl;
}

// =========================
// BAI 3
// Tao ma don hang
// =========================
string createOrderCode(string customerName, string phone) {
    customerName = normalizeDishName(customerName);

    string firstPart = "";

    for (char c : customerName) {
        if (isalpha((unsigned char)c)) {
            firstPart += toupper(c);

            if (firstPart.length() == 3)
                break;
        }
    }

    if (firstPart.length() == 0)
        firstPart = "KH";

    string last4 = phone;

    if (phone.length() > 4)
        last4 = phone.substr(phone.length() - 4);

    time_t now = time(0);
    tm* localTime = localtime(&now);

    int year = 1900 + localTime->tm_year;

    return firstPart + to_string(year) + last4;
}

void bai3() {
    string name, phone;

    cout << "\n===== BAI 3: TAO MA DON HANG =====\n";

    cout << "Nhap ten khach hang: ";
    getline(cin, name);

    cout << "Nhap so dien thoai: ";
    getline(cin, phone);

    string code = createOrderCode(name, phone);

    cout << "Ma don hang: " << code << endl;
}

// =========================
// BAI 4
// Kiem tra mon an
// =========================
void bai4() {
    string dish;

    cout << "\n===== BAI 4: KIEM TRA MON AN =====\n";
    cout << "Danh sach mon an:\n";

    for (string item : menuDishes) {
        cout << "- " << item << endl;
    }

    cout << "\nNhap ten mon an can kiem tra: ";
    getline(cin, dish);

    dish = normalizeDishName(dish);

    bool found = false;

    for (string item : menuDishes) {
        if (normalizeDishName(item) == dish) {
            found = true;
            break;
        }
    }

    if (found)
        cout << "Mon an co trong danh sach cua hang.\n";
    else
        cout << "Mon an khong co trong danh sach cua hang.\n";
}

// =========================
// BAI 6
// Thay doi trang thai don hang
// =========================
void bai6() {
    string code;
    string newStatus;

    cout << "\n===== BAI 6: THAY DOI TRANG THAI DON HANG =====\n";

    cout << "\nDanh sach don hang:\n";

    for (const Order& order : orders) {
        cout << "Ma: " << order.code
             << " | Khach: " << order.customerName
             << " | Trang thai: " << order.status << endl;
    }

    cout << "\nNhap ma don hang: ";
    getline(cin, code);

    bool found = false;

    for (Order& order : orders) {
        if (order.code == code) {
            found = true;

            cout << "Trang thai hien tai: "
                 << order.status << endl;

            cout << "\nTrang thai moi:\n";
            cout << "1. Dang chuan bi\n";
            cout << "2. Dang giao\n";
            cout << "3. Hoan thanh\n";
            cout << "4. Da huy\n";

            int choice;
            cout << "Chon: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1)
                newStatus = "Dang chuan bi";
            else if (choice == 2)
                newStatus = "Dang giao";
            else if (choice == 3)
                newStatus = "Hoan thanh";
            else if (choice == 4)
                newStatus = "Da huy";
            else {
                cout << "Lua chon khong hop le!\n";
                return;
            }

            order.status = newStatus;

            cout << "Da cap nhat trang thai thanh: "
                 << order.status << endl;

            break;
        }
    }

    if (!found)
        cout << "Khong tim thay ma don hang!\n";
}

// =========================
// BAI 7
// Tim don hang theo ten khach
// =========================
string toLowerString(string s) {
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z')
            c = c + ('a' - 'A');
    }

    return s;
}

void bai7() {
    string keyword;

    cout << "\n===== BAI 7: TIM DON HANG THEO TEN KHACH =====\n";

    cout << "Nhap tu khoa ten khach hang: ";
    getline(cin, keyword);

    keyword = toLowerString(keyword);

    bool found = false;

    cout << "\nKet qua tim kiem:\n";

    for (const Order& order : orders) {
        string customer = toLowerString(order.customerName);

        if (customer.find(keyword) != string::npos) {
            found = true;

            cout << "-----------------------------\n";
            cout << "Ma don hang: " << order.code << endl;
            cout << "Khach hang: " << order.customerName << endl;
            cout << "So dien thoai: " << order.phone << endl;
            cout << "Mon an: " << order.dish << endl;
            cout << "So luong: " << order.quantity << endl;
            cout << "Trang thai: " << order.status << endl;
            cout << "Dia chi: " << order.address << endl;
        }
    }

    if (!found)
        cout << "Khong tim thay don hang phu hop.\n";
}

// =========================
// BAI 9
// Thong ke mon an ban chay
// =========================
void bai9() {
    string dish;

    cout << "\n===== BAI 9: THONG KE MON AN BAN CHAY =====\n";

    cout << "Nhap ten mon an: ";
    getline(cin, dish);

    dish = normalizeDishName(dish);

    int count = 0;

    for (const Order& order : orders) {
        if (normalizeDishName(order.dish) == dish) {
            count++;
        }
    }

    cout << "Mon \"" << dish << "\" da xuat hien trong "
         << count << " don hang.\n";
}

// =========================
// BAI 10
// Tao thong bao giao hang
// =========================
void bai10() {
    string customer;
    string code;
    string address;

    cout << "\n===== BAI 10: TAO THONG BAO GIAO HANG =====\n";

    cout << "Nhap ten khach hang: ";
    getline(cin, customer);

    cout << "Nhap ma don hang: ";
    getline(cin, code);

    cout << "Nhap dia chi giao hang: ";
    getline(cin, address);

    string message =
        "Don hang [" + code + "] cua [" +
        customer + "] dang duoc giao den [" +
        address +
        "]. Cam on ban!";

    cout << "\n===== THONG BAO =====\n";
    cout << message << endl;
}

// =========================
// MENU CHINH
// =========================
void showMenu() {
    cout << "\n\n========================================\n";
    cout << "       QUAN LY CUA HANG GIAO DO AN\n";
    cout << "========================================\n";
    cout << "1. Nhap va hien thi ten cua hang\n";
    cout << "2. Chuan hoa ten mon an\n";
    cout << "3. Tao ma don hang\n";
    cout << "4. Kiem tra mon an\n";
    cout << "5. Thay doi trang thai don hang\n";
    cout << "6. Tim don hang theo ten khach\n";
    cout << "7. Thong ke mon an ban chay\n";
    cout << "8. Tao thong bao giao hang\n";
    cout << "0. Thoat\n";
    cout << "========================================\n";
}

int main() {
    int choice;

    do {
        showMenu();

        cout << "Nhap lua chon: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            bai1();
            break;

        case 2:
            bai2();
            break;

        case 3:
            bai3();
            break;

        case 4:
            bai4();
            break;

        case 5:
            bai6();
            break;

        case 6:
            bai7();
            break;

        case 7:
            bai9();
            break;

        case 8:
            bai10();
            break;

        case 0:
            cout << "\nKet thuc chuong trinh!\n";
            break;

        default:
            cout << "\nLua chon khong hop le!\n";
        }

    } while (choice != 0);

    return 0;
}