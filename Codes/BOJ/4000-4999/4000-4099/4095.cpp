#include <bits/stdc++.h>
using namespace std;

string input;
int n, m;
int board[1001][1001], DP[1001][1001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		for (int j = 1; j <= m; j++) {
			board[i][j] = input[j - 1] - '0';
		}
	}

	int solve = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j]) {
				DP[i][j] = min({ DP[i - 1][j - 1], DP[i - 1][j], DP[i][j - 1] }) + 1;
				solve = max(solve, DP[i][j]);
			}
		}
	}

	cout << solve * solve << '\n';
}