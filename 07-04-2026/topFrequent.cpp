#include <iostream>
#include <unordered_map>

using namespace std;

void inputArray(int arr[], int n) {
for (int i = 0; i < n; i++) {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }
}

void topKFrequent(int nums[], int n, int k) {
    unordered_map<int, int> counts;
    
    for (int i = 0; i < n; i++) {
        counts[nums[i]]++;
    }

    int values[1000];
    int freqs[1000];
    int size = 0;

    for (auto it = counts.begin(); it != counts.end(); it++) {
        values[size] = it->first;
        freqs[size] = it->second;
        size++;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (freqs[j] < freqs[j + 1]) {
                int tempFreq = freqs[j];
                freqs[j] = freqs[j + 1];
                freqs[j + 1] = tempFreq;

                int tempVal = values[j];
                values[j] = values[j + 1];
                values[j + 1] = tempVal;
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << values[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter n: ";
    cin >> n;

    int arr[1000];
    inputArray(arr, n);   
 
    cout << "Enter k: ";
    cin >> k;

    topKFrequent(arr, n, k);

    return 0;
}
