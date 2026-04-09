#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double getSlope(string name, double x) {
    if (name == "square") return 2 * x;
    if (name == "sin")    return cos(x);
    if (name == "exp")    return exp(x);
    return 1;
}

int main() {
    string funcs[] = {"sin", "square"};
    int size = 2;
    double x = 1.0;

    double result = 1.0;

    for (int i = size - 1; i >= 0; i--) {
        result *= getSlope(funcs[i], x);
    }

    cout << result << endl;

    return 0;
}
