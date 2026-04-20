#include <iostream>
#include <stack>
#include <string>
using namespace std;

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
            int k;
            cout << "Enter number of char to delete: ";
            cin >> k;

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
            text = history.top();
            history.pop();
            cout << "Enter 'type', 'delete', 'print', or 'undo': ";
        }
    }

    return 0;
}