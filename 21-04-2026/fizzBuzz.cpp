#include <iostream>
#include <string>
using namespace std;

bool isFizz(int num) {
	return (num % 3 == 0);
}

bool isBuzz(int num) {
	return (num % 5 == 0);
}

int main() {
	for (int i = 1; i <= 50; i++) {
		if (isFizz(i) && isBuzz(i)) {
			cout << "FizzBuzz ";
		} else if (isBuzz(i)) {
			cout << "Buzz ";
		} else if (isFizz(i)) {
			cout << "Fizz ";
		} else {
			cout << i << " ";
		}
	}
	return 0;
}