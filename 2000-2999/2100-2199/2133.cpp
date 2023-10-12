#include <bits/stdc++.h>
using namespace std;

const int MAX = 30;
int dp[31];
int N;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= N; i += 2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}

	cout << dp[N] << '\n';
}	