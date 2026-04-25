#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream create("secret.txt");
    create << "The AGENT sent a SECRET Message to BASE camp. Code: ALPHA-7." << endl;
    create.close();

    ifstream file("secret.txt");
    if (!file) { cout << "Error opening file!" << endl; return 1; }

    char ch;
    int count = 0;

    while (file.get(ch)) {
        if (ch >= 'A' && ch <= 'Z')
            count++;
    }

    file.close();
    cout << "Uppercase signal count: " << count << endl;
    return 0;
}