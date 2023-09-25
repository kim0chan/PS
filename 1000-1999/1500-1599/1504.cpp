#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, E;
int a, b, c, u, v;
int dist[801][801];

int calculateDistance(int st, int en) {
	if (dist[1][st] == INF || dist[st][en] == INF || dist[en][N] == INF) return INF;
	return dist[1][st] + dist[st][en] + dist[en][N];
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans;
	cin >> N >> E;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)	continue;
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = c;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	cin >> u >> v;
	ans = min(calculateDistance(u, v), calculateDistance(v, u));
	if (ans == INF) ans = -1;

	cout << ans << '\n';
}