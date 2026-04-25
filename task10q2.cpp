#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream file("diary.txt", ios::app);
    if (!file) { cout << "Error opening file!" << endl; return 1; }

    string line;
    cout << "Write your diary entry (type 'exit' to stop):" << endl;

    while (true) {
        getline(cin, line);
        if (line == "exit") break;
        file << line << endl;
    }

    file.close();
    cout << "Diary entry saved to diary.txt" << endl;
    return 0;
}

