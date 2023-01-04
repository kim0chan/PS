#include <bits/stdc++.h>
using namespace std;

int dp[30];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	dp[0] = 0;
	dp[1] = 1;

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n] << '\n';
}