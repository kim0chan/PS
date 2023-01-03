#include <bits/stdc++.h>

using namespace std;

int dp[11];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;

	int T;
	cin >> T;
	for (int i = 3; i < 11; i++) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	while (T--) {
		int N;
		cin >> N;

		cout << dp[N - 1] << '\n';
	}
}