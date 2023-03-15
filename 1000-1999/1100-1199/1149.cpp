#include <bits/stdc++.h>
using namespace std;

int N;
int cost[3][1001];
int solve[3][1001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	////// 0:R, 1:G, 2:B
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[j][i];
		}
	}

	solve[0][1] = cost[0][1];
	solve[1][1] = cost[1][1];
	solve[2][1] = cost[2][1];

	for (int i = 2; i <= N; i++) {
		solve[0][i] = min(solve[1][i - 1], solve[2][i - 1]) + cost[0][i];
		solve[1][i] = min(solve[2][i - 1], solve[0][i - 1]) + cost[1][i];
		solve[2][i] = min(solve[0][i - 1], solve[1][i - 1]) + cost[2][i];
	}

	/*
	cout << "[DEBUG]\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cout << solve[j][i] << ' ';
		}
		cout << '\n';
	}
	*/

	cout << min(solve[0][N], min(solve[1][N], solve[2][N])) << '\n';
}