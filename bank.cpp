#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    static double bankFunds;

public:
    BankAccount(string holder, double initialBalance) {
        accountHolder = holder;
        balance = initialBalance;
        bankFunds += initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        bankFunds += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) return false;
        balance -= amount;
        bankFunds -= amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }

    static double getBankFunds() {
        return bankFunds;
    }
};

double BankAccount::bankFunds = 0.0;

int main() {
    BankAccount acc1("Alice", 1000);
    BankAccount acc2("Bob", 1500);

    acc1.deposit(500);
    acc2.withdraw(200);

    cout << "Total bank funds: " << BankAccount::getBankFunds() << endl;
    return 0;
}
