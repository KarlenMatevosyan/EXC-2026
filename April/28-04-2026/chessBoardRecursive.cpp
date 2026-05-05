#include <iostream>
#include <vector>
using namespace std;

void printBoard(int board[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool canMove(int board[8][8], int x, int y) {
	return (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == 0);
}

bool chessBoardRecursive(int board[8][8], int x, int y, vector<vector<int>>& moves, int moveCount) {
	if (moveCount == 64) {
		return true;
	}


	for (const auto& move : moves) {
		int posX = x + move[0];
		int posY = y + move[1];
		if (canMove(board, posX, posY)) {
			//cout << posX << "-" << posY << endl;
			board[posX][posY] = moveCount + 1;

			if (chessBoardRecursive(board, posX, posY, moves, moveCount + 1)) {
				return true;
			}

			board[posX][posY] = 0;
		}
	}
	return false;
}

int main() {
	const int N = 8;
	int board[8][8] = {0};
	vector<vector<int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
	int x = 0, y = 0;
	board[x][y] = 1;

	chessBoardRecursive(board, x, y, moves, 1);

	cout << "\n--- Printing Board ---" << endl;
	printBoard(board);
	return 0;
}
