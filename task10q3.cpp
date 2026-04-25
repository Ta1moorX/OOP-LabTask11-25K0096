#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, email, choice;

    do {
        cout << "Enter name:  ";
        getline(cin, name);
        cout << "Enter email: ";
        getline(cin, email);

        ofstream file("signup.txt", ios::app);
        if (!file) { cout << "Error opening file!" << endl; return 1; }

        file << "Name: " << name << ", Email: " << email << endl;
        file.close();
        cout << "Registered successfully!" << endl;

        cout << "Add another? (yes/no): ";
        getline(cin, choice);
    } while (choice == "yes");

    cout << "All registrations saved to signup.txt" << endl;
    return 0;
}