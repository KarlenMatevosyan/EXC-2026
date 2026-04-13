#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void strSum(string a, string b) {
	int size_a = a.length();
	int size_b = b.length();
	
	if (size_a < size_b) {
		swap(a, b);
		swap(size_a, size_b);
	}

	int diff = size_a - size_b;
	int res[100] = {0}; 
	int k = size_a; 
	int add = 0;

	for (int i = size_a - 1; i >= diff; i--) {
		int digit_a = a[i] - '0';
		int digit_b = b[i - diff] - '0';
		
		int sum = digit_a + digit_b + add;
		res[k] = sum % 10;
		add = sum / 10;
		k--;
	}

	for (int i = diff - 1; i >= 0; i--) {
		int sum = (a[i] - '0') + add;
		res[k] = sum % 10;
		add = sum / 10;
		k--;
	}

	if (add) {
		res[k] = add;
	} else {
		k++;
	}

	for (int i = k; i <= size_a; i++) {
		cout << res[i];
	}
	cout << endl;
}

int main() {
    string s1, s2;
    cout << "Enter 1st string: ";
    cin >> s1;
    cout << "Enter 2nd string: ";
    cin >> s2;
    
	strSum(s1, s2);
	return 0;
}
