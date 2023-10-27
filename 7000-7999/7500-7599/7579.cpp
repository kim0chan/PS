#include <bits/stdc++.h>
using namespace std;

int N, M;
int mem[101];
int cost[101];
int dp[101][10001];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
	int ans = -1;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> mem[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= sum; j++) {
			if (cost[i] <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + mem[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int i = 0; i <= sum; i++) {
		if (dp[N][i] >= M) {
			cout << i << '\n';
			return 0;
		}
	}

}