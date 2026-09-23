#include <iostream>
#include <string>

using namespace std;

struct Food {
    string id;
    string name;
    double price;
    int quantity;
};

struct OrderItem {
    string foodId;
    string foodName;
    double price;
    int quantity;
};

struct Order {
    string id;
    string customerName;
    string address;
    OrderItem items[50];
    int itemCount;
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

int main() {
    Restaurant restaurant;

    inputRestaurant(restaurant);

    cout << "\nThong tin cua hang:\n";
    cout << "Ten: " << restaurant.name << endl;
    cout << "Dia chi: " << restaurant.address << endl;
    cout << "So dien thoai: " << restaurant.phone << endl;

    return 0;
}