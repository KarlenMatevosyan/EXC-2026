#include <iostream>
#include <string>
using namespace std;

bool isValid(string str) {
    int size = str.length();
    char stack[size];
    int top = -1;
    
    for (int i = 0; i < size; i++) {
        char current = str[i];
        if (current == '(' || current == '[' || current == '{') {
            stack[++top] = current;
        } else {
            if (top == -1) {
                return false;
            }
            char open = stack[top--];
            
            if (current == ')' && open != '(') return false;
            if (current == ']' && open != '[') return false;
            if (current == '}' && open != '{') return false;
        }
    }
    return (top == -1);
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;
    
    if (isValid(str)) {
        cout << "True ";
    } else {
        cout << "False ";
    }
    
    return 0;
}
