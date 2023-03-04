#include <bits/stdc++.h>

using namespace std;

int T[1500001];
int P[1500001];
int dp[1500001];
int N;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = N; i >= 1; i--) {
		if (i + T[i] <= N + 1) {
			dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
		}
		else dp[i] = dp[i + 1];
	}

	cout << *max_element(dp, dp + N + 1) << '\n';
}