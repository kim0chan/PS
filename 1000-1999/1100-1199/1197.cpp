#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int v, e;
vector<pair<int, int>> adj[10001];
bool chk[10001];

int main(void) {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	chk[1] = true;
	int cnt = 0;
	int ans = 0;

	for (auto next : adj[1]) {
		pq.push({ next.X, 1, next.Y });
	}
	while (cnt < v - 1) {
		int c, a, b;
		tie(c, a, b) = pq.top();	pq.pop();
		if (chk[b])	continue;
		ans += c;
		chk[b] = 1;
		cnt++;

		for (auto next : adj[b]) {
			if (!chk[next.Y]) {
				pq.push({ next.X, b, next.Y });
			}
		}
	}
	cout << ans << '\n';
}
