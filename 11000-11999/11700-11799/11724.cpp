#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int N, M;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	while (M--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int solve = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i])	continue;
		solve++;
		queue<int> qu;
		qu.push(i);
		visited[i] = true;
		while (!qu.empty()) {
			int cur = qu.front();	qu.pop();
			for (auto next : adj[cur]) {
				if (visited[next])	continue;
				qu.push(next);
				visited[next] = true;
			}
		}
	}
	cout << solve << '\n';
}