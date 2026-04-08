#include <iostream>
#include <algorithm>
using namespace std;

void inputArray(int first[], int second[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter " << i + 1 << " interval: ";
        cin >> first[i] >> second[i];
    }
}

void mergeIntervals(int first[], int second[], int size) {
    if (size <= 0) {
        return;
    }

    sort(first, first + size);
    sort(second, second + size);

    cout << "Result: ";
    int startIdx = 0;
    for (int i = 0; i < size; i++) {
        if (i == size - 1 || first[i + 1] > second[i]) {
            cout << "[" << first[startIdx] << "," << second[i] << "] ";
            startIdx = i + 1;
        }
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;


    int first[size];
    int second[size];

    inputArray(first, second, size);
    mergeIntervals(first, second, size);

    return 0;
}
