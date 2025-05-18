#include <bits/stdc++.h>

using namespace std;

long long int dp[105];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	for (int i = 4; i <= 101; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		cout << dp[N] << '\n';
	}
}