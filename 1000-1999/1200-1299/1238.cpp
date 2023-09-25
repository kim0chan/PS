#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, X;
int A, B, T;
int dist[1001][1001];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> X;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)	continue;
			dist[i][j] = INF;
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> A >> B >> T;
		dist[A][B] = min(dist[A][B], T);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int mx = 0;
	for (int i = 1; i <= N; i++) {
		mx = max(mx, dist[i][X] + dist[X][i]);
	}
	cout << mx << '\n';
}