#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, message;
    cout << "Enter recipient's name: ";
    getline(cin, name);
    cout << "Enter your message: ";
    getline(cin, message);

    ofstream file("greeting.txt");
    if (!file) { cout << "Error opening file!" << endl; return 1; }

    file << "Dear " << name << "," << endl;
    file << message << endl;
    file << "Best Regards!" << endl;

    file.close();
    cout << "Greeting saved to greeting.txt" << endl;
    return 0;
}