#include <iostream>
using namespace std;

bool isValidSudoku(char arr[9][9]) {
	for (int row = 0; row < 9; row++) {
		bool seen[10] = {0};
		for (int col = 0; col < 9; col++) {
			if (arr[row][col] != '.') {                  // for rows
				int num = arr[row][col] - '0';
				if (seen[num]) {
					return false;
				}
				seen[num] = true;
			}
		}
	}

	for (int col = 0; col < 9; col++) {
		bool seen[10] = {0};
		for (int row = 0; row < 9; row++) {             // for columns
			if (arr[row][col] != '.') {
				int num = arr[row][col] - '0';
				if (seen[num]) {
					return false;
				}
				seen[num] = true;
			}
		}
	}

	return true;
}

int main() {
	char arr[9][9] = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	if (isValidSudoku(arr)) {
		cout << "Valid" << endl;
	} else {
		cout << "Not Valid" << endl;
	}

	return 0;
}
