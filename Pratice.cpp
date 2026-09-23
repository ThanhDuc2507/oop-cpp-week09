#include <iostream>
#include <string>

using namespace std;

struct Food {
    string id;
    string name;
    double price;
    int quantity;
};

struct Order {
    string id;
    string customerName;
    string address;
    Food food;
    int quantity;
    string status;
};

struct Restaurant {
    string name;
    string address;
    string phone;

    Food foods[100];
    int foodCount;

    Order orders[100];
    int orderCount;
};

void inputRestaurant(Restaurant &r) {
    cout << "Nhap ten cua hang: ";
    getline(cin, r.name);

    cout << "Nhap dia chi: ";
    getline(cin, r.address);

    cout << "Nhap so dien thoai: ";
    getline(cin, r.phone);

    r.foodCount = 0;
    r.orderCount = 0;
}

void addFood(Restaurant &r) {
    if (r.foodCount >= 100) {
        cout << "Danh sach mon an da day!\n";
        return;
    }

    Food &f = r.foods[r.foodCount];

    cout << "\n===== THEM MON AN =====\n";

    cout << "Nhap ma mon: ";
    getline(cin, f.id);

    cout << "Nhap ten mon: ";
    getline(cin, f.name);

    cout << "Nhap don gia: ";
    cin >> f.price;

    cout << "Nhap so luong: ";
    cin >> f.quantity;

    cin.ignore();

    r.foodCount++;

    cout << "Them mon an thanh cong!\n";
}

void displayFoods(const Restaurant &r) {
    cout << "\n===== DANH SACH MON AN =====\n";

    if (r.foodCount == 0) {
        cout << "Chua co mon an nao!\n";
        return;
    }

    for (int i = 0; i < r.foodCount; i++) {
        cout << "\nMon an " << i + 1 << endl;
        cout << "Ma mon: " << r.foods[i].id << endl;
        cout << "Ten mon: " << r.foods[i].name << endl;
        cout << "Don gia: " << r.foods[i].price << endl;
        cout << "So luong: " << r.foods[i].quantity << endl;
    }
}

void searchFood(const Restaurant &r) {
    string keyword;

    cout << "\n===== TIM MON AN =====\n";
    cout << "Nhap ma hoac ten mon can tim: ";
    getline(cin, keyword);

    bool found = false;

    for (int i = 0; i < r.foodCount; i++) {
        if (r.foods[i].id == keyword ||
            r.foods[i].name == keyword) {

            cout << "\nTim thay mon an:\n";
            cout << "Ma mon: " << r.foods[i].id << endl;
            cout << "Ten mon: " << r.foods[i].name << endl;
            cout << "Don gia: " << r.foods[i].price << endl;
            cout << "So luong: " << r.foods[i].quantity << endl;

            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay mon an!\n";
    }
}

int main() {
    Restaurant restaurant;

    inputRestaurant(restaurant);

    addFood(restaurant);

    displayFoods(restaurant);

    searchFood(restaurant);

    return 0;
}