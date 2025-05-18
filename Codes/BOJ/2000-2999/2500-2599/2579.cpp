#include <bits/stdc++.h>

using namespace std;

int step[500];
int dp[500];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> step[i];
	}

	dp[1] = step[1];

	for (int i = 2; i <= N; i++) {
		int a, b, max;
		a = step[i - 1];
		if (i > 3) {
			a = a + dp[i - 3];
		}
		b = dp[i - 2];

		max = (a > b) ? a : b;
		dp[i] = step[i] + max;
	}

	cout << dp[N] << '\n';
}