#include <bits/stdc++.h>
using namespace std;

int DP[10001][3];
int T, n;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	DP[1][0] = 1;
	DP[2][0] = 1;
	DP[2][1] = 1;
	DP[3][0] = 1;
	DP[3][1] = 1;
	DP[3][2] = 1;

	cin >> T;
	while (T--) {
		cin >> n;

		for (int i = 4; i <= n; i++) {
			if (DP[i][0])	continue;

			DP[i][0] = 1;
			DP[i][1] = DP[i - 2][1] + DP[i - 2][0];
			DP[i][2] = DP[i - 3][2] + DP[i - 3][1] + DP[i - 3][0];
		}
		cout << DP[n][0] + DP[n][1] + DP[n][2] << '\n';
	}
}