#include <bits/stdc++.h>

using namespace std;
#define INF		999999
#define IDX(x)	x - 1
#define MIN(a, b)	a<b ? a:b

int adj[101][101];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int min = INF;
	int minidx = -1;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) adj[i][j] = 0;
			else adj[i][j] = INF;
		}
	}

	while (M--) {
		int a, b;
		cin >> a >> b;
		adj[IDX(a)][IDX(b)] = adj[IDX(b)][IDX(a)] = 1;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				adj[i][j] = MIN(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			sum += adj[i][j] == INF ? 0 : adj[i][j];
		}
		if (sum < min) {
			min = sum;
			minidx = i + 1;
		}
	}

	cout << minidx << '\n';
}