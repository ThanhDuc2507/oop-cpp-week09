#include <iostream>
using namespace std;

void printNames() {
    cout << "Huynh Nguyen Thanh Duc" << endl;
}

void solveLinearEquation(double a, double b) {
    if (a == 0) {
        if (b == 0) {
            cout << "Equation has infinitely many solutions (Vo so nghiem)." << endl;
        } else {
            cout << "Equation has no solution (Vo nghiem)." << endl;
        }
    } else {
        double x = -b / a;
        cout << "Equation has one root x = " << x << endl;
    }
}

int main() {
    // Test Exercise 1
    cout << "--- Exercise 1 ---" << endl;
    printNames();
    cout << endl;

    // Test Exercise 2
    cout << "--- Exercise 2 ---" << endl;
    double a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    solveLinearEquation(a, b);

    return 0;
}