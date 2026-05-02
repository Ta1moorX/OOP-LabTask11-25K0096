#include <iostream>
using namespace std;

class InsufficientFundsException {};

class BankAccount {
public:
    int bal;
    BankAccount(int b) {
        bal = b;
    }
    void withdraw(int amt) {
        if (amt > bal) throw InsufficientFundsException();
        bal -= amt;
        cout << "Withdrawal successful! New Balance: $" << bal << endl;
    }
};

int main() {
    BankAccount acc(500);
    int w;

    cout << "Current Balance: $" << acc.bal << endl;
    cout << "Enter withdrawal amount: ";
    cin >> w;

    try {
        acc.withdraw(w);
    } catch (InsufficientFundsException) {
        cout << "Error: Insufficient funds to complete withdrawal!" << endl;
    }
}