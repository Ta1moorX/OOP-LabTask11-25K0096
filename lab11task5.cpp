#include <iostream>
#include <string>
using namespace std;

template <class T>
T findMax(T arr[], int n) {
    T m = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > m) m = arr[i];
    }
    return m;
}

int main() {
    int a[] = {10, 20, 5, 30, 25};
    cout << "Array: [10, 20, 5, 30, 25]" << endl;
    cout << "Maximum: " << findMax(a, 5) << endl;

    string s[] = {"Apple", "Mango", "Banana", "Peach"};
    cout << "Array: [Apple, Mango, Banana, Peach]" << endl;
    cout << "Maximum: " << findMax(s, 4) << endl;
}