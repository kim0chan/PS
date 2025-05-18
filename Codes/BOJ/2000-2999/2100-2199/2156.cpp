#include <bits/stdc++.h>

using namespace std;

int amount[10005];
int dp[10005];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> amount[i];
	}

	dp[n] = amount[n];
	if (n >= 2) {
		dp[n - 1] = amount[n - 1] + amount[n];
	}

	for (int i = n - 2; i > 0; i--) {
		int max = 0;
		int a = 0;
		int b = 0;
		int bigger;
		for (int j = i + 2; j <= n; j++) {
			a = dp[j];
			if (j != n) { b = amount[i + 1] + dp[j + 1]; }
			else { b = amount[i + 1]; }
			bigger = (a > b) ? a : b;
			max = (max > bigger) ? max : bigger;
		}
		dp[i] = amount[i] + max;
	}


	int solve = 0;
	for (int i = 1; i <= n; i++) {
		solve = (solve > dp[i]) ? solve : dp[i];
	}

	cout << solve << '\n';
}