#include <bits/stdc++.h>

using namespace std;

int _map[101][101];
long long int dp[101][101];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> _map[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (_map[i][j] == 0) { continue; }
			if (i + _map[i][j] < N) { dp[i + _map[i][j]][j] += dp[i][j]; }
			if (j + _map[i][j] < N) { dp[i][j + _map[i][j]] += dp[i][j]; }
		}
	}

	/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	*/

	cout << dp[N - 1][N - 1] << '\n';
}