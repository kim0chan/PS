#include <bits/stdc++.h>
#define COST	first
#define DEST	second
using namespace std;
typedef long long ll;

const ll INF = 0x7f7f7f7f7f7f;
int N, M, K;
vector<pair<ll, int>> adj[100001];
ll dist[100001];


int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int U, V;
		ll C;

		cin >> U >> V >> C;
		adj[V].push_back({ C, U });
	}

	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

	for (int i = 0; i < K; i++) {
		int site;
		cin >> site;
		dist[site] = 0;
		pq.push({ dist[site], site });
	}

	while (!pq.empty()) {
		auto cur = pq.top();	pq.pop();
		if (dist[cur.DEST] != cur.COST)	continue;

		for (auto nxt : adj[cur.DEST]) {
			if (dist[nxt.DEST] <= dist[cur.DEST] + nxt.COST)	continue;
			dist[nxt.DEST] = dist[cur.DEST] + nxt.COST;
			pq.push({dist[nxt.DEST], nxt.DEST});
		}
	}

	int idx = max_element(dist + 1, dist + N + 1) - dist;

	cout << idx << '\n' << dist[idx] << '\n';

}