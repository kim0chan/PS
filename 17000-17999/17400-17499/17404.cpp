#include <bits/stdc++.h>
using namespace std;

const int INF = 1000001;
int N;
int cost[1001][3];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int ans = INF;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cost[i][0];
		cin >> cost[i][1];
		cin >> cost[i][2];
	}

	for (int st = 0; st < 3; st++) {
		int dp[1001][3];
		for (int i = 0; i < 3; i++) {
			dp[0][i] = (i != st) ? INF : cost[0][i];
		}

		for (int i = 1; i < N; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		for (int i = 0; i < 3; i++) {
			if (i == st)	continue;
			ans = min(ans, dp[N - 1][i]);
		}
	}

	cout << ans << '\n';
}