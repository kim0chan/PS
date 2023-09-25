#include <bits/stdc++.h>
using namespace std;
#define COST	first
#define NAME	second

const int INF = 0x3f3f3f3f;
int N, M, A, B;
int u, v, c, src, dst;
int dist[1001];
vector<pair<int, int>> adj[1001];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	fill(dist, dist + N + 1, INF);
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> c;
		adj[u].push_back({ c, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	cin >> src >> dst;
	dist[src] = 0;
	pq.push({ dist[src], src });

	while (!pq.empty()) {
		auto cur = pq.top();	pq.pop();
		if (cur.COST != dist[cur.NAME])	continue;
		for (auto nxt : adj[cur.NAME]) {
			if (dist[nxt.NAME] <= dist[cur.NAME] + nxt.COST)	continue;
			dist[nxt.NAME] = dist[cur.NAME] + nxt.COST;
			pq.push({ dist[nxt.NAME], nxt.NAME });
		}
	}

	cout << dist[dst] << '\n';
}