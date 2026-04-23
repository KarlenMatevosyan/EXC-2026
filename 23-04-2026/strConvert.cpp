#include<iostream>
#include<string>

using namespace std;

string strDecode(string input) {
    int size = input.size();
    string result = "";

    for (int i = 0; i < size; i++) {
        int num = input[i] - '0';
        if (num >= 1 && num <= 9) {
            char letter = num + 'A' - 1; 
            cout << letter;
        }
    }
    cout << endl;

    for (int i = 1; i < size; i++) {
        int twoDigit = (input[i - 1] - '0') * 10 + (input[i] - '0');
        if (twoDigit >= 10 && twoDigit <= 26) {
            char letter = twoDigit + 'A' - 1; 
            cout << letter << " ";
        }
    }
    cout << endl;

    return result;
}

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    string result = strDecode(input);
    cout << "Decoded string: " << result << endl;

    return 0;
}