#include <bits/stdc++.h>
using namespace std;

int plum[1001];
int DP[1001][31];
int T, W;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> T >> W;

	for (int i = 0; i < T; i++) {
		cin >> plum[i];
	}

	DP[0][0] = (plum[0] == 1) ? 1 : 0;
	DP[0][1] = (plum[0] == 2) ? 1 : 0;

	for (int i = 1; i < T; i++) {
		DP[i][0] = DP[i - 1][0] + (plum[i] == 1);
		for (int j = 1; j <= W; j++) {
			int a, b;
			a = DP[i - 1][j - 1];
			b = DP[i - 1][j];
			DP[i][j] = max(a, b) + (plum[i] == (j%2) + 1);
		}
	}

	/*
	for (int i = 0; i < T; i++) {
		for (int j = 0; j <= W; j++) {
			cout << DP[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	cout << *max_element(DP[T - 1], DP[T - 1] + W+1) << '\n';
}