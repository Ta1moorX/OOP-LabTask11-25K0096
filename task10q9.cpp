#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream create("draft.txt");
    create << "I think teh quick brown fox is very fast." << endl;
    create << "teh second line also has content." << endl;
    create.close();

    fstream file("draft.txt", ios::in | ios::out);
    if (!file) { cout << "Error opening file!" << endl; return 1; }

    string content = "", line;
    while (getline(file, line))
        content += line + "\n";

    size_t pos = content.find("teh");
    if (pos != string::npos) {
        file.seekp(pos);
        file.write("the", 3);
        cout << "Fixed: 'teh' -> 'the' at position " << pos << endl;
    } else {
        cout << "No typo found." << endl;
    }

    file.close();

    ifstream verify("draft.txt");
    cout << "\n=== Corrected draft.txt ===" << endl;
    while (getline(verify, line))
        cout << line << endl;
    verify.close();

    return 0;
}