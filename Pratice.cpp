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

            cout << "\nMa mon: " << r.foods[i].id << endl;
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

void updateFood(Restaurant &r) {
    string id;

    cout << "\n===== CAP NHAT MON AN =====\n";
    cout << "Nhap ma mon can cap nhat: ";
    getline(cin, id);

    for (int i = 0; i < r.foodCount; i++) {
        if (r.foods[i].id == id) {

            cout << "Nhap don gia moi: ";
            cin >> r.foods[i].price;

            cout << "Nhap so luong moi: ";
            cin >> r.foods[i].quantity;

            cin.ignore();

            cout << "Cap nhat thanh cong!\n";
            return;
        }
    }

    cout << "Khong tim thay mon an!\n";
}

void createOrder(Restaurant &r) {
    if (r.foodCount == 0) {
        cout << "Chua co mon an de dat hang!\n";
        return;
    }

    Order &o = r.orders[r.orderCount];

    cout << "\n===== TAO DON HANG =====\n";

    cout << "Nhap ma don hang: ";
    getline(cin, o.id);

    cout << "Nhap ten khach hang: ";
    getline(cin, o.customerName);

    cout << "Nhap dia chi giao hang: ";
    getline(cin, o.address);

    cout << "Nhap ma mon: ";
    string foodId;
    getline(cin, foodId);

    int foodIndex = -1;

    for (int i = 0; i < r.foodCount; i++) {
        if (r.foods[i].id == foodId) {
            foodIndex = i;
            break;
        }
    }

    if (foodIndex == -1) {
        cout << "Mon an khong ton tai!\n";
        return;
    }

    cout << "Nhap so luong: ";
    cin >> o.quantity;
    cin.ignore();

    if (o.quantity > r.foods[foodIndex].quantity) {
        cout << "Khong du so luong mon an!\n";
        return;
    }

    o.food = r.foods[foodIndex];
    o.food.quantity = o.quantity;
    o.status = "Cho xu ly";

    r.foods[foodIndex].quantity -= o.quantity;

    r.orderCount++;

    cout << "Tao don hang thanh cong!\n";
}

void checkFood(Restaurant &r) {
    string id;
    int quantity;

    cout << "\n===== KIEM TRA MON AN =====\n";

    cout << "Nhap ma mon: ";
    getline(cin, id);

    int index = -1;

    for (int i = 0; i < r.foodCount; i++) {
        if (r.foods[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Mon an khong ton tai!\n";
        return;
    }

    cout << "Nhap so luong can kiem tra: ";
    cin >> quantity;
    cin.ignore();

    if (r.foods[index].quantity >= quantity) {
        cout << "Mon an ton tai va du so luong!\n";
    }
    else {
        cout << "Mon an ton tai nhung khong du so luong!\n";
    }
}

int main() {
    Restaurant restaurant;

    inputRestaurant(restaurant);

    addFood(restaurant);

    displayFoods(restaurant);

    searchFood(restaurant);

    updateFood(restaurant);

    createOrder(restaurant);

    checkFood(restaurant);

    return 0;
}