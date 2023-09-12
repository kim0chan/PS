#include <bits/stdc++.h>
using namespace std;

int N;
int R[1001];
int G[1001];
int B[1001];
int min_cost[1001][3];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> R[i] >> G[i] >> B[i];
	}

	min_cost[0][0] = R[0];
	min_cost[0][1] = G[0];
	min_cost[0][2] = B[0];

	for (int i = 1; i < N; i++) {
		min_cost[i][0] = min(min_cost[i - 1][1], min_cost[i - 1][2]) + R[i];
		min_cost[i][1] = min(min_cost[i - 1][2], min_cost[i - 1][0]) + G[i];
		min_cost[i][2] = min(min_cost[i - 1][0], min_cost[i - 1][1]) + B[i];
	}

	cout << min({ min_cost[N - 1][0], min_cost[N - 1][1], min_cost[N - 1][2] }) << '\n';
}