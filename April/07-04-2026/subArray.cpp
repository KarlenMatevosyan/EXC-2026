#include <iostream>
#include <unordered_map>
using namespace std;

void inputArray (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter arr[" << i << "] - ";
        cin >> arr[i];
    }
    cout << endl;
}

int subarraySum(int nums[], int size, int k) {
    unordered_map<int, int> sumCount;
    sumCount[0] = 1;

    int currentSum = 0;
    int count = 0;

    for (int i = 0; i < size; i++) {
        currentSum += nums[i];
        
        int target = currentSum - k;
        if (sumCount.find(target) != sumCount.end()) {
            count += sumCount[target];
        }

        sumCount[currentSum]++;
    }

    return count;
}

int main() {
    int size, k;
    cout << "Enter array size: ";
    cin >> size;
    int arr[size];
    
    cout << "Enter k: ";
    cin >> k;

    inputArray(arr, size);

    cout << "Result: " << subarraySum(arr, size, k) << endl;

    return 0;
}
