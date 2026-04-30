#include <iostream>

using namespace std;

const int N = 7;

bool isValid(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < N);
}

int countNeighbors(bool board[N][N], int r, int c) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            
            int newR = r + i;
            int newC = c + j;
            
            if (isValid(newR, newC) && board[newR][newC]) {
                count++;
            }
        }
    }
    return count;
}

void update(bool board[N][N]) {
    bool result[N][N] = {false};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int neighbors = countNeighbors(board, i, j);
            if (board[i][j]) {
                result[i][j] = (neighbors == 2 || neighbors == 3);
            } else {
                result[i][j] = (neighbors == 3);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = result[i][j];
        }
    }
}

void draw(bool board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "# " : ". ");
        }
        cout << endl;
    }
    cout << "-------------------------------" << endl;
}

int main() {
    bool board[N][N] = {false};

    board[1][2] = true;
    board[2][3] = true;
    board[3][1] = true;
    board[3][2] = true;
    board[3][3] = true;

    while (true) {
        draw(board);
        update(board);
        cin.ignore(); 
    }

    return 0;
}
