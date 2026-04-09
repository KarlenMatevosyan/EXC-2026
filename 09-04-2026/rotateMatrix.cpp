#include <iostream>
using namespace std;

const int N = 3; 

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void rotate90(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < N; i++) {
        int start = 0;
        int end = N - 1;
        swap(matrix[i][start], matrix[i][end]);
    } 
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int matrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printMatrix(matrix);
    rotate90(matrix);
    printMatrix(matrix);

    return 0;
}
