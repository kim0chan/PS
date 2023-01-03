#include <bits/stdc++.h>

using namespace std;

long long int dp[1000005];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	dp[1] = 1;
	dp[2] = 2;

	int N;
	cin >> N;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[N] << '\n';

}