#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ofstream create("article.txt");
    for (int i = 1; i <= 30; i++)
        create << "Line " << i << ": This is content of the article at line " << i << "." << endl;
    create.close();

    ifstream file("article.txt");
    if (!file) { cout << "Error opening file!" << endl; return 1; }

    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();

    file.seekg(fileSize / 2);

    string temp;
    getline(file, temp);

    cout << "=== Preview from middle of article ===" << endl;
    string line;
    int count = 0;
    while (count < 10 && getline(file, line)) {
        cout << line << endl;
        count++;
    }

    file.close();
    return 0;
}