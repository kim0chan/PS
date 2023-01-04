#include <bits/stdc++.h>

#define divisor	10007

using namespace std;

long long int dp[1005][10];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	
	int solve = 0;
	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			long long int value = 0;
			for (int k = j; k < 10; k++) {
				value += dp[i - 1][k];
			}
			dp[i][j] = value % divisor;
		}
	}

	for (int i = 0; i < 10; i++) {
		solve += dp[N][i];
	}

	cout << solve % divisor << '\n';;
}