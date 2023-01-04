#include <bits/stdc++.h>

using namespace std;

int A[1005];
int dp[1005];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int max = 0;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
	}
	for (int i = N - 2; i >= 0; i--) {
		int local_max = 0;
		int j = i + 1;
		while (j < N) {
			if (A[j] > A[i]) {
				local_max = (local_max > dp[j]) ? local_max : dp[j];
			}
			j++;
		}
		dp[i] += local_max;
	}

	for (int i = 0; i < N; i++) {
		max = (max >= dp[i]) ? max : dp[i];
	}

	cout << max << '\n';
}