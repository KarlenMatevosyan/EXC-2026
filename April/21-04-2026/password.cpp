#include <iostream>
#include <string>
using namespace std;

int main() {
	bool hasDigit, hasUpper, hasLower, hasSymbol, has6, hasSpace = false;
	string password;
	cout << "Enter your password: ";
	getline(cin, password);
	int size = password.length();
	
	if (size <= 6) {
		has6 = true;
	} else {
		for (char c : password) {
			if (c > '0' && c < '9') {
				hasDigit = true;
			} else if (c > 'A' && c < 'Z') {
				hasUpper = true;
			} else if (c > 'a' && c < 'z') {
				hasLower = true;
			} else if (c == 32) {
				hasSpace = true;
			} else {
				hasSymbol = true;
			}
		}
	}
	if (hasSpace) {
	    cout << "No spaces allowed." << endl;
	} else {
		if (!has6) {
			if (hasDigit && hasUpper && hasLower && hasSymbol) {
				cout << "Password strength is strong." << endl;
			} else if (hasDigit && hasLower) {
				cout << "Password strength is medium." << endl;
			} else {
				cout << "Password strength is weak." << endl;
			}
		} else {
			cout << "Password strength is weak, less than 6 digits..." << endl;
		}
	}
	

	return 0;
}