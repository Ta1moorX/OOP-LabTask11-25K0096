#include <iostream>
#include <string>
using namespace std;

class OutOfBoundsException {};

template <class T>
class SmartArray {
public:
    T *arr;
    int size;

    SmartArray(int n) {
        size = n;
        arr = new T[n];
    }

    T& operator[](int i) {
        if (i < 0 || i >= size) throw OutOfBoundsException();
        return arr[i];
    }
};

int main() {
    int n = 5;
    SmartArray<int> a(n);

    cout << "Array size: " << n << endl;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a.arr[i];

    try {
        cout << "Accessing index 2: " << a[2] << endl;
        cout << "Accessing index 5: " << endl;
        cout << a[5] << endl;
    } catch (OutOfBoundsException) {
        cout << "OutOfBoundsException caught: Invalid index access attempted!" << endl;
    }
}