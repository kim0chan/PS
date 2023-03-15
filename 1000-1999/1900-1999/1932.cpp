#include <bits/stdc++.h>
using namespace std;

int field[501][501];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> field[i][j];
		}
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				field[i][j] += field[i - 1][j];
			}
			else if (i == j) {
				field[i][j] += field[i - 1][j - 1];
			}
			else {
				field[i][j] += max(field[i - 1][j - 1], field[i - 1][j]);
			}
		}
	}

	int solve = 0;
	for (int i = 1; i <= N; i++) {
		solve = max(solve, field[N][i]);
	}

	cout << solve << '\n';
}