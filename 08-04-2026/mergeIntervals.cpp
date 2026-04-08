#include <iostream>
#include <algorithm>
using namespace std;

void inputArray(int first[], int second[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter " << i + 1 << " interval: ";
        cin >> first[i] >> second[i];
    }
}

void addInterval(int first[], int second[], int size) {
    cout << "Enter new interval: ";
    cin >> first[size] >> second[size];
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


    int first[size + 1];
    int second[size + 1];

    inputArray(first, second, size);
    addInterval(first, second, size);
    mergeIntervals(first, second, size + 1);

    return 0;
}
