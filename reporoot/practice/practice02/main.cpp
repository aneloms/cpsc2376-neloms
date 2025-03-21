#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string FILENAME = "account_balance.txt";

double readBalanceFromFile() {
    ifstream file(FILENAME);
    double balance;
    if (file) {
        file >> balance;
    } else {
        balance = 100.00;
        ofstream outFile(FILENAME);
        outFile << fixed << setprecision(2) << balance;
    }
    return balance;
}

void writeBalanceToFile(double balance) {
    ofstream file(FILENAME);
    if (!file) {
        cerr << "Error: Could not open file for writing!" << endl;
        exit(1);
    }
    file << fixed << setprecision(2) << balance;
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << fixed << setprecision(2) << balance << endl;
}

double deposit(double balance) {
    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Error: Deposit amount must be positive." << endl;
        return balance;
    }
    balance += amount;
    writeBalanceToFile(balance);
    cout << "Deposit successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
    return balance;
}

double withdraw(double balance) {
    double amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    if (amount <= 0) {
        cout << "Error: Withdrawal amount must be positive." << endl;
        return balance;
    }
    if (amount > balance) {
        cout << "Error: Insufficient funds. Your balance is $" << fixed << setprecision(2) << balance << "." << endl;
        return balance;
    }
    balance -= amount;
    writeBalanceToFile(balance);
    cout << "Withdrawal successful. Your new balance is: $" << fixed << setprecision(2) << balance << endl;
    return balance;
}

int main() {
    double balance = readBalanceFromFile();
    cout << "Welcome to Your Bank Account!" << endl;
    
    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                cout << "Exiting program. Have a nice day!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);
    
    return 0;
}
