#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int getMin(int board[][51], int x, int y) {
	int result1, result2, min;
	int count = 0;
	int com = 1;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((com != board[x + i][y + j])) { count++; }

			if (com == 1) { com = 0; }
			else { com = 1; }
		}
		if (com == 1) { com = 0; }
		else { com = 1; }
	}

	result1 = count;
	count = 0;
	com = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((com != board[x + i][y + j])) { count++; }

			if (com == 1) { com = 0; }
			else { com = 1; }
		}
		if (com == 1) { com = 0; }
		else { com = 1; }
	}

	result2 = count;
	min = (result1 < result2) ? result1 : result2;
	return min;
}

int main(void) {
	int N, M;
	int board[51][51] = { 0, };
	int min;
	int com;
	char input;

	cin >> N >> M;

	min = 2147483647;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			if (input == 'W') { board[i][j] = 0; }
			else if (input == 'B') { board[i][j] = 1; }
		}
	}

	for (int i = 0; i <= (N - 8); i++) {
		for (int j = 0; j <= (M - 8); j++) {
			com = getMin(board, i, j);
			if (min > com) { min = com; }
		}
	}

	cout << min;
	return 0;
}