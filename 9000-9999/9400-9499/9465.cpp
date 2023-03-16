#include <bits/stdc++.h>
using namespace std;

int T, n;
int sticker[2][100004];
int DP[2][100004];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> sticker[i][j];
			}
		}

		DP[0][0] = sticker[0][0];
		DP[1][0] = sticker[1][0];
		DP[0][1] = sticker[1][0] + sticker[0][1];
		DP[1][1] = sticker[0][0] + sticker[1][1];

		for (int i = 2; i < n; i++) {
			DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + sticker[0][i];
			DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + sticker[1][i];
		}
		/*
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cout << DP[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
		cout << max(DP[0][n-1], DP[1][n-1]) << '\n';
	}
}