#include <iostream>
using namespace std;

class InvalidAgeException {};
class InvalidSalaryException {};
class InvalidHeightException {};

int main() {
    int age, salary, height;

    cout << "Enter age: ";
    cin >> age;
    try {
        if (age <= 0 || age >= 120) throw InvalidAgeException();
    } catch (InvalidAgeException) {
        cout << "InvalidAgeException caught: Age must be between 1 and 119" << endl;
    }

    cout << "Enter salary: ";
    cin >> salary;
    try {
        if (salary <= 0) throw InvalidSalaryException();
    } catch (InvalidSalaryException) {
        cout << "InvalidSalaryException caught: Salary must be positive" << endl;
    }

    cout << "Enter height: ";
    cin >> height;
    try {
        if (height <= 0) throw InvalidHeightException();
    } catch (InvalidHeightException) {
        cout << "InvalidHeightException caught: Height must be positive" << endl;
    }
}