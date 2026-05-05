#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string RESET = "\033[0m";

const int withdrawLimit = 400;
const int depositLimit = 10000;
const int maxBalance = 10000;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isInt(string s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;    
}

class Person {
private:
    string name;
    int balance;
    vector<string> history;

public:
    Person(string name, int balance = 0) {
        this->name = name;
        this->balance = balance;
    }

    void printBalance() {
        cout << GREEN << name << "'s balance: " << balance << endl << RESET;
    }

    void deposit(int amount) {
    if (amount > depositLimit) {
        cout << RED << "Amount exceeds deposit limit!" << endl << RESET;
    } 
    else if (balance + amount > maxBalance) { 
        cout << RED << "Balance cannot exceed " << maxBalance << "!" << endl << RESET;
    } 
    else {
        balance += amount;
        history.push_back("Deposit: " + to_string(amount));
    }
}

    void withdraw(int amount) {
        if (amount >= balance) {
            cout << RED << "Insufficient funds!" << endl << RESET;
        } else if (amount > withdrawLimit){
            cout << RED << "Amount exceeds withdraw limit!" << endl << RESET;
        } else {
            balance -= amount;
            history.push_back("Withdraw: " + to_string(amount));
        }
    }

    void showHistory() {
        cout << GREEN << name << "'s transaction history:" << endl << RESET;
        for (string record : history) {
            cout << record << endl;
        }
        printBalance();
    }

};
int main() {
    string user;
    cout << "Enter your name: ";
    cin >> user;
    Person ob1(user);
    string input;

    cout << "Enter 'deposit' to deposit, 'withdraw' to withdraw, 'history' to view history, or 'exit' to quit: ";

    while (cin >> input) {
        if (input == "deposit") {
            string amountStr;
            cout << "Enter amount to deposit: ";
            cin >> amountStr;

            if (!isInt(amountStr)) {
                cout << RED << "Invalid amount!" << endl << RESET;
                continue;
                cout << "Enter 'deposit' to deposit, 'withdraw' to withdraw, 'history' to view history, or 'exit' to quit: ";
            }

            int amount = stoi(amountStr);
            ob1.deposit(amount);
        } else if (input == "withdraw") {
            string amountStr;
            cout << "Enter amount to withdraw: ";
            cin >> amountStr;
            if (!isInt(amountStr)) {
                cout << RED << "Invalid amount!" << endl << RESET;
                continue;
                cout << "Enter 'deposit' to deposit, 'withdraw' to withdraw, 'history' to view history, or 'exit' to quit: ";
            }
            int amount = stoi(amountStr);
            ob1.withdraw(amount);
        } else if (input == "exit") {
            break;
        } else if (input == "balance") {
            ob1.printBalance();
        } else if (input == "history") {
            ob1.showHistory();
        } else {
            cout << RED << "Invalid command!" << endl << RESET;
        }
        cout << "Enter 'deposit' to deposit, 'withdraw' to withdraw, 'history' to view history, or 'exit' to quit: ";
    }
    return 0;
}