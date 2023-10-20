#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	int a_length = (int)a.size();
	int b_length = (int)b.size();

	for (int j = 1; j <= b_length; j++) {
		if (a[0] == b[j - 1])	dp[1][j] = 1;
		else						dp[1][j] = dp[1][j - 1];
	}

	for (int i = 2; i <= a_length; i++) {
		for (int j = 1; j <= b_length; j++) {
			if (a[i - 1] == b[j - 1])	dp[i][j] = dp[i - 1][j - 1] + 1;
			else						dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[a_length][b_length] << '\n';
}