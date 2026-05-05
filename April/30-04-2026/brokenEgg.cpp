#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter floors you want to try: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Please enter positive number.." << endl;
        return 1;
    }

    int drops = 0;
    int sum = 0;

    while (sum < n) {
        drops++;
        sum += drops;
    }

    cout << "The maximum tries - " << drops << endl;

    int current_floor = 0;
    while (current_floor < n && drops > 0) {
        current_floor += drops;
        if (current_floor > n) current_floor = n;
        cout << current_floor << " ";
        drops--;
    }
    cout << endl;

    return 0;
}
