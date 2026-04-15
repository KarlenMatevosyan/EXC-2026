#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string convert(string num, int base1, int base2) {
    int size = num.length();
    unsigned long long value = 0;
    if (size > 20) {
        return "";
    }
    
    for (int i = 0; i < size; i++) {
        value = value * base1 + num[i] - '0';
    }
    //cout << value << endl;
    
    string result = "";
    while (value > 0) {   
        int remaind = value % base2;
        result += char(remaind + '0');
        value /= base2;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string final = convert("534007", 9, 7);
    cout << final;
    return 0;
}
