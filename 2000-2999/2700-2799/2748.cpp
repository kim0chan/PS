#include <bits/stdc++.h>

using namespace std;

long long int dp[100];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[n];
}