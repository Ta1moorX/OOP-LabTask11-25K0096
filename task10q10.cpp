#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string message;
    cout << "Log Monitor (type 'exit' to stop)" << endl;

    while (true) {
        cout << "\nEnter log message: ";
        getline(cin, message);
        if (message == "exit") break;

        ofstream file("backup_log.txt", ios::app);
        if (!file) { cout << "Error opening file!" << endl; return 1; }

        file << message << endl;

        streampos size = file.tellp();
        file.close();

        cout << "Entry saved. Current file size: " << size << " bytes" << endl;
    }

    cout << "Backup log closed." << endl;
    return 0;
}