#include <bits/stdc++.h>
#define COST	first
#define	DST		second
using namespace std;

int v, e, st;
vector<pair<int, int>> adj[20001];
const int INF = 0x3f3f3f3f;
int d[20001];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> st;
	fill(d, d + v + 1, INF);

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[st] = 0;
	pq.push({ d[st], st });

	while (!pq.empty()) {
		auto cur = pq.top();	pq.pop();
		if (d[cur.DST] != cur.COST)	continue;
		for (auto next : adj[cur.DST]) {
			if (d[next.DST] <= d[cur.DST] + next.COST)	continue;
			d[next.DST] = d[cur.DST] + next.COST;
			pq.push({ d[next.DST], next.DST });
		}
	}


	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF\n";
		else cout << d[i] << '\n';
	}
}