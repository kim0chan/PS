#include <bits/stdc++.h>
#define DIV		1000000009
using namespace std;

long long int dp[1000005];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;

	int T;
	cin >> T;

	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % DIV;
	}

	while (T--) {
		int n;
		cin >> n;

		cout << dp[n] << '\n';
	}
}