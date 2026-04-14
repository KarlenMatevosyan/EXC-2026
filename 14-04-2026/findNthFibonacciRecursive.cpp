#include <iostream>
using namespace std;

int findNFibonacci(long long num, long long first = 1, long long second = 1, int index = 2) {
    if (second == num) {
        return index;
    }
    
    if (second > num) {
        return -1;
    }
    
    return findNFibonacci(num, second, first + second, index + 1);
}

int main() {
    long long num;
    cout << "Enter num: ";
    cin >> num;
    int result = findNFibonacci(num);
    
    if(result != -1) {
        cout << num << " is the " << result << "th of fibonacci sequence. ";
    } else {
        cout << result << " | Not in fibonacci sequence." << endl;
    }
    
    return 0;
}
