#include <bits/stdc++.h>
#define COST	first
#define DST		second
using namespace std;

int N, M;
int cnt, solve, maxc;
vector<pair<int, int>> adj[100001];
bool chk[100001];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	chk[1] = true;
	for (auto next : adj[1]) {
		pq.push({ next.COST, 1, next.DST });
	}

	while (cnt < N - 1) {
		int c, a, b;
		tie(c, a, b) = pq.top();	pq.pop();
		if (chk[b])	continue;
		cnt++;
		solve += c;
		maxc = max(maxc, c);
		chk[b] = true;

		for (auto next : adj[b]) {
			if (chk[next.DST])	continue;
			pq.push({ next.COST, b, next.DST });
		}
	}

	cout << solve - maxc << '\n';
}