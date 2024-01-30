#include <bits/stdc++.h>

using namespace std;

#define divisor	1000000000

long long int dp[105][15];

int main() {
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	long long int solve = 0;
	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			long long int value;

			if (j == 0) { value = dp[i - 1][1] % divisor; }
			else if (j == 9) { value = dp[i - 1][8] % divisor; }
			else {
				value = dp[i - 1][j - 1] + dp[i - 1][j + 1] % divisor;
			}

			dp[i][j] = value;
		}
	}

	for (int i = 1; i < 10; i++) {
		solve += dp[N][i];
	}

	cout << solve % divisor  << '\n';
}