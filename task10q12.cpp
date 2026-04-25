#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream create("article.txt");
    for (int i = 1; i <= 20; i++)
        create << "Line " << i << ": Sample content for the file debugger tool. ";
    create.close();

    ifstream file("article.txt");
    if (!file) { cout << "Error opening file!" << endl; return 1; }

    file.seekg(0, ios::end);
    streampos fileSize = file.tellg();
    cout << "File size: " << fileSize << " bytes" << endl;

    char choice;
    do {
        long offset;
        cout << "\nEnter byte offset (0 to " << fileSize << "): ";
        cin >> offset;

        if (offset < 0 || offset >= fileSize) {
            cout << "Offset out of range!" << endl;
        } else {
            file.seekg(offset);
            cout << "Pointer BEFORE read: " << file.tellg() << endl;

            cout << "\n=== Next 100 characters ===" << endl;
            char buf[101] = {0};
            file.read(buf, 100);
            cout << buf << endl;

            cout << "\nPointer AFTER read:  " << file.tellg() << endl;
        }

        cout << "\nInspect another offset? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y');

    file.close();
    return 0;
}