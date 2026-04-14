#include <iostream>
#include <string>

using namespace std;

long long strToInt(string num) {
    long long res = 0;
    for (int i = 0; i < num.length(); i++) {
        res = res * 10 + (num[i] - '0');
    }
    return res;
}

int findNthFibonacci(long long num, long long first = 1, long long second = 1, int index = 2) {
    if (second == num) {
        return index;
    }

    if (second > num) {
        return -1;
    }

    return findNthFibonacci(num, second, first + second, index + 1);
}

int main() {
    string num;
    cout << "Enter num: ";
    cin >> num;

    long long number = strToInt(num);
    
    
    int result = findNthFibonacci(number);
    cout << result << endl;

    return 0;
}
