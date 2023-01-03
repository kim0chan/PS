#include <bits/stdc++.h>

using namespace std;

int dp[100005];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (!i) {
			dp[i] = input;
		}
		else {
			dp[i] = (input > dp[i - 1] + input) ? input : dp[i - 1] + input;
		}
	}

	int max = -999999;
	for (int i = 0; i < n; i++) {
		max = (max > dp[i]) ? max : dp[i];
	}
	cout << max;
}