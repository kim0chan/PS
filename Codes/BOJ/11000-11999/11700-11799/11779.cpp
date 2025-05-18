#include <bits/stdc++.h>
#define COST	first
#define DST		second
using namespace std;

const int INF = 0x3f3f3f3f;
int n, m, src, dst;
vector<pair<int, int>> adj[1001];
int d[1001];
int pre[1001];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ c, b });
	}
	cin >> src >> dst;
	fill(d, d + n + 1, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[src] = 0;
	pq.push({ d[src], src });

	while (!pq.empty()) {
		auto cur = pq.top();	pq.pop();
		if (cur.COST != d[cur.DST])	continue;

		for (auto next : adj[cur.DST]) {
			if (d[next.DST] <= d[cur.DST] + next.COST)	continue;
			d[next.DST] = d[cur.DST] + next.COST;
			pre[next.DST] = cur.DST;
			pq.push({ d[next.DST], next.DST });
		}
	}

	cout << d[dst] << '\n';
	vector<int> path;
	int c = dst;
	while (c != src) {
		path.push_back(c);
		c = pre[c];
	}
	path.push_back(c);
	cout << (int)path.size() << '\n';
	reverse(path.begin(), path.end());
	for (auto a : path) {
		cout << a << ' ';
	}
	cout << '\n';

}