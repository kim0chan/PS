#include <bits/stdc++.h>
using namespace std;

#define IDX(x)	x-1

int board[1025][1025];
int board_DP[1025][1025];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board_DP[i][j] += board[i][j];
			if (j > 0) {
				board_DP[i][j] += board_DP[i][j - 1];
			}
			if (i > 0) {
				board_DP[i][j] += board_DP[i - 1][j];
			}
			if (i > 0 && j > 0) {
				board_DP[i][j] -= board_DP[i - 1][j - 1];
			}
		}
	}

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board_DP[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	*/
	
	while (M--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int solve = board_DP[IDX(x2)][IDX(y2)];
		if (IDX(x1) > 0) {
			solve -= board_DP[IDX(x1) - 1][IDX(y2)];
		}
		if (IDX(y1) > 0) {
			solve -= board_DP[IDX(x2)][IDX(y1) - 1];
		}
		if (IDX(x1) > 0 && IDX(y1) > 0) {
			solve += board_DP[IDX(x1) - 1][IDX(y1) - 1];
		}

		cout << solve << '\n';
	}
}