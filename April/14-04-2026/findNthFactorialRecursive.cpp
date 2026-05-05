#include <iostream>
using namespace std;

int findNthFactorial(long long num, int current = 1) {
    if (num == 1) {
        return current - 1;
    }
    
    if (num % current != 0) {
        return -1;
    }
    
    return findNthFactorial(num / current, current + 1);
}

int main() {
    long long num;
    cout << "Enter num: ";
    cin >> num;

    int result = findNthFactorial(num);
    if (result != -1) {
        cout << num << " is the factorial of " << result;
    } else {
        cout << result << "| No factorial ";
    }

    return 0;
}
