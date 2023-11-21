#include <bits/stdc++.h>
using namespace std;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans = 1, N, M;

	cin >> N;
	vector<int> dp(N + 1);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cin >> M;
	int st = 0;
	for (int i = 0; i < M; i++) {
		int vip;
		cin >> vip;
		ans *= dp[vip - (st + 1)];
		st = vip;
	}
	ans *= dp[N - st];

	cout << ans << '\n';
}