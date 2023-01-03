#include <bits/stdc++.h>

using namespace std;

long long dp[95];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	dp[1] = 1;
	dp[2] = 1;
	int N;
	cin >> N;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[N] << '\n';
}