#include <bits/stdc++.h>
using namespace std;

int N;
int DP[1000001];
int PREV[1000001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;

	for (int i = 2; i <= N; i++) {
		int min = 1000001;
		int prev = -1;

		if (i % 3 == 0) {
			if (DP[i / 3] < min) {
				min = DP[i / 3];
				prev = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (DP[i / 2] < min) {
				min = DP[i / 2];
				prev = i / 2;
			}
		}

		if (DP[i - 1] < min) {
			min = DP[i - 1];
			prev = i - 1;
		}

		DP[i] = min + 1;
		PREV[i] = prev;
	}

	cout << DP[N] << '\n';
	while (N) {
		cout << N << ' ';
		N = PREV[N];
	}
}