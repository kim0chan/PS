#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T[20];
	int P[20];
	int dp[20];
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = N; i >= 1; i--) {
		int max = 0;

		for (int j = i + T[i]; j <= N; j++) {
			max = (max > dp[j]) ? max : dp[j];
		}
		if (i + T[i] > N + 1) { dp[i] = 0; }
		else { dp[i] = max + P[i]; }
	}

	int solve = 0;

	for (int i = 1; i <= N; i++) {
		//cout << dp[i] << ' ';
		solve = (solve > dp[i]) ? solve : dp[i];
	}

	cout << solve << '\n';
}