#include <iostream>
using namespace std;

template <class T>
void swapValues(T &a, T &b) {
    T t = a;
    a = b;
    b = t;
}

int main() {
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "After swap: a = " << a << ", b = " << b << endl;

    float x = 3.5, y = 7.8;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl;

    char c1 = 'A', c2 = 'Z';
    cout << "Before swap: ch1 = " << c1 << ", ch2 = " << c2 << endl;
    swapValues(c1, c2);
    cout << "After swap: ch1 = " << c1 << ", ch2 = " << c2 << endl;
}