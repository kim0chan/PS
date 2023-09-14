#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101001];
int dist[101001];
int N, K, M;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= K; j++) {
			int dst;
			cin >> dst;
			adj[N + i].push_back(dst);
			adj[dst].push_back(N + i);
		}
	}

	queue<int> qu;
	qu.push(1);
	dist[1] = 1;

	while(!qu.empty()) {
		int cur = qu.front();	qu.pop();
		for (auto next : adj[cur]) {
			if (dist[next]) continue;
			qu.push(next);
			dist[next] = dist[cur] + 1;
		}
	}

	if (dist[N] == 0) cout << -1 << '\n';
	else cout << (dist[N]) / 2 + 1 << '\n';
}