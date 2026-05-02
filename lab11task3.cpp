#include <iostream>
#include <string>
using namespace std;

template <class T, class U>
class Pair {
public:
    T a;
    U b;
    Pair(T x, U y) {
        a = x;
        b = y;
    }
    void display() {
        cout << "Pair: (" << a << ", " << b << ")" << endl;
    }
};

int main() {
    Pair<int, string> p1(5, "Hello");
    p1.display();

    Pair<float, int> p2(3.14, 42);
    p2.display();
}