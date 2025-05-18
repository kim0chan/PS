#include <bits/stdc++.h>

using namespace std;

long long int dp[100][11];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= 64; i++) {
		for (int j = 9; j >= 0; j--) {
			dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
		}
	}

	while (T--) {
		long long int sum = 0;
		int n;
		cin >> n;

		for (int i = 0; i < 10; i++) {
			sum += dp[n][i];
		}

		cout << sum << '\n';
	}

}