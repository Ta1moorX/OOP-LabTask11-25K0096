#include <iostream>
using namespace std;

int main() {
    int n, d;
    cout << "Enter numerator: ";
    cin >> n;
    cout << "Enter denominator: ";
    cin >> d;

    try {
        if (d == 0) throw d;
        cout << "Result: " << n / d << endl;
    } catch (...) {
        cout << "Error: Division by zero is not allowed!" << endl;
    }
}