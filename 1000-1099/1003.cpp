#include <bits/stdc++.h>

using namespace std;

#define Z	first
#define O	second

pair<int, int> dp[100];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	dp[0] = { 1, 0 };
	dp[1] = { 0, 1 };
	int calculated = 1;

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;

		if (N > calculated) {
			for (int i = calculated + 1; i <= N; i++) {
				dp[i].Z = dp[i - 1].Z + dp[i - 2].Z;
				dp[i].O = dp[i - 1].O + dp[i - 2].O;
			}
			calculated = N;
		}

		cout << dp[N].Z << ' ' << dp[N].O << '\n';
	}
}