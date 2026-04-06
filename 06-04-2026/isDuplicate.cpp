#include <iostream>
#include <unordered_set>
using namespace std;

void inputArray (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter arr[" << i << "] - ";
        cin >> arr[i];
    }
    cout << endl;
}

void printArray (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isDuplicate(int arr[], int size) {
    unordered_set<int> res;
    
    for (int i = 0; i < size; i++) {
        if (res.find(arr[i]) != res.end()) {
            return true;
        }
        res.insert(arr[i]);
    }
    return false;
}

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;
    int arr[size];
    
    inputArray(arr, size);
    printArray(arr, size);
    
    if (isDuplicate(arr, size)) {
        cout << "True: Duplicate exists " << endl;
    } else {
        cout << "No Duplicate exist " << endl;
    }
    
    return 0;
}
