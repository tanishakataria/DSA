#include<iostream>
using namespace std;

class BankAccount {
private:
    double* balance; // Pointer to store balance dynamically

public:
    // Default Constructor
    BankAccount() {
        balance = new double(0);
        cout << "Default constructor called. Balance is $ :" << *balance << endl;
    }

    // Parameterized Constructor
    BankAccount(double initialBalance) {
        balance = new double(initialBalance);
        cout << "Parameterized constructor called. Balance is $ :" << *balance << endl;
    }

    // Copy Constructor
    BankAccount(const BankAccount &other) {
        balance = new double(*other.balance);
        cout << "Copy constructor called. Balance is $ :" << *balance << endl;
    }

    // Destructor
    ~BankAccount() {
        delete balance;
        cout << "Destructor called, memory released." << endl;
    }

    // Method to deduct an amount from balance
    void deduct(double amount) {
        if (*balance >= amount) {
            *balance -= amount;
            cout << "Deducted $" << amount << " from balance. New balance: $" << *balance << endl;
        } else {
            cout << "Insufficient funds to deduct $" << amount << ". Balance remains: $" << *balance << endl;
        }
    }

    // Method to get the balance
    double getBalance() {
        return *balance;
    }
};

int main() {
    // a) Default Constructor Usage
    BankAccount account1;
    cout << "Account 1 Balance is: $" << account1.getBalance() << endl;

    // b) Parameterized Constructor Usage
    BankAccount account2(1000);
    cout << "Account 2 Balance is: $" << account2.getBalance() << endl;

    // c) Copy Constructor Usage
    BankAccount account3(account2);  // Explicitly use the copy constructor
    cout << "Account 3 Balance immediately after creation: $" << account3.getBalance() << endl;

    account3.deduct(200);
    cout << "Account 3 Balance after deduction is: $" << account3.getBalance() << endl;
    cout << "Account 2 Balance remains the same: $" << account2.getBalance() << endl;

    return 0;
}
