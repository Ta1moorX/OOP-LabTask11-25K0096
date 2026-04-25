#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    ofstream create("story.txt");
    create << "The quick brown fox jumps over the lazy dog near the river bank." << endl;
    create.close();

    ifstream file("story.txt");
    if (!file) { cout << "Error opening file!" << endl; return 1; }

    string line, word;
    cout << "=== Words ===" << endl;

    while (getline(file, line)) {
        istringstream iss(line);
        while (iss >> word)
            cout << word << endl;
    }

    file.close();
    return 0;
}