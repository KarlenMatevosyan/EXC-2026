#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void strSub(string a, string b) {
	int size_a = a.length();
	int size_b = b.length();
	
	if (size_a < size_b || (size_a == size_b && a < b)) {
		swap(a, b);
		swap(size_a, size_b);
		cout << "-";
	}

	int diff = size_a - size_b;
	int res[20] = {0}; 
	int k = size_a - 1; 
	int add = 0;

	for (int i = size_a - 1; i >= 0; i--) {
		int digit_a = a[i] - '0';
		int digit_b = (i >= diff) ? (b[i - diff] - '0') : 0;
		
		int sub = digit_a - digit_b - add;

		if (sub < 0) {
			sub = sub + 10;
			add = 1;
		} else {
			add = 0;
		}

		res[i] = sub;
	}

	int start = 0;
	while (start < size_a - 1 && res[start] == 0) {
		start++;
	}

	for (int i = start; i < size_a; i++) {
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
    
	strSub(s1, s2);
	
	return 0;
}
