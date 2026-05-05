#include <iostream>
#include <string>

using namespace std;

string strToRLE(string str) {
	string res = "";
	int size = str.length();

	for (int i = 0; i < size; i++) {
		int count = 1;
		
		while (i < size - 1 && str[i] == str[i + 1]) {
			count++;
			i++;
		}

		if (count >= 2) {
			res += char(count + '0');
		}
		
		res += str[i];
	}

	return res;
}

int main() {
	string str;
	cout << "Enter string: ";
	cin >> str;
	cout << strToRLE(str) << endl;
	
	return 0;
}
