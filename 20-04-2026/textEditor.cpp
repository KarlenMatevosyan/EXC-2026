#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isInt(string s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;    
}

int main() {
    string text = "";
    stack<string> history;

    string command;

    cout << "Enter 'type', 'delete', 'print', or 'undo': ";
    while (cin >> command) {
        if (command == "type") {
            string word;
            cout << "Enter word to type: ";
            cin >> word;

            history.push(text); 

            if (!text.empty()) {
                text += " ";
            }
            text += word;
            cout << "Enter 'type', 'delete', 'print', or 'undo': ";
        }
        else if (command == "delete") {
            string kstr;
            cout << "Enter number of char to delete: ";
            cin >> kstr;
            
            if (!isInt(kstr)) {
                cout << "Invalid k type value..." << endl;
                cout << "Enter 'type', 'delete', 'print', or 'undo': ";
                continue;
            }
            
            int k = stoi(kstr);
            if (k < 0) {
                cout << "Invalid k value..." << endl;
                cout << "Enter 'type', 'delete', 'print', or 'undo': ";
                continue;
            }

            history.push(text); 

            while (k > 0 && !text.empty()) {
                text.pop_back();
                k--;
            }
            cout << "Enter 'type', 'delete', 'print', or 'undo': ";
        }
        else if (command == "print") {
            cout << text << endl;
            cout << "Enter 'type', 'delete', 'print', or 'undo': ";
        }
        else if (command == "undo") {
            if (!text.empty()) {
                text = history.top();
                history.pop();
            } else {
                cout << "You can not type 'undo' at first... " << endl;
                cout << "Enter 'type', 'delete', 'print', or 'undo': ";
                continue;
            }
            cout << "Enter 'type', 'delete', 'print', or 'undo': ";
        }
    }

    return 0;
}
