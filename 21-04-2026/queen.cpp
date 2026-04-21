#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

void printBoard(int board[MAX][MAX], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                cout << " Q ";
            } else {
                cout << " * ";
            }
        }
        cout << endl;
    }
}

bool isSafe(int board[MAX][MAX], int row, int col, int N) {
    int i, j;

    for (i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    
    for (i = row + 1, j = col - 1; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool setQueens(int board[MAX][MAX], int col, int N) {
    if (col == N) {
        printBoard(board, N);
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[i][col] = 1;

            if (setQueens(board, col + 1, N)) {
                return true;
            }

            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    int N;
    cout << "Enter the size (max 10): ";
    cin >> N;

    if (N > MAX) {
        cout << "N is too large!" << endl;
        return 1;
    }

    int board[MAX][MAX] = {0};

    setQueens(board, 0, N);
    //printBoard(board, N);
    return 0;
}