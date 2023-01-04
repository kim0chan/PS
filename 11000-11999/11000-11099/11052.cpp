#include <bits/stdc++.h>

using namespace std;

int price[1004];
int dp[1004];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}
	dp[0] = 0;
	dp[1] = price[1];

	for (int i = 2; i <= N; i++) {
		int max = -1;
		for (int j = 1; j * 2 <= i; j++) {
			int sum = dp[j] + dp[i - j];
			max = (max > sum) ? max : sum;
		}
		max = (max > price[i]) ? max : price[i];
		dp[i] = max;
	}

	cout << dp[N] << '\n';
}