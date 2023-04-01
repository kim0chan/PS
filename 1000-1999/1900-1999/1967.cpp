#include <bits/stdc++.h>
using namespace std;

int N, A, B, C;
int max_dist, max_node;
vector<pair<int, int>> adj[100001];
bool visited[100001];

void dfs(int cur, int dist) {
	if (max_dist < dist) {
		max_dist = dist;
		max_node = cur;
	}
	for (pair<int, int> next : adj[cur]) {
		if (visited[next.first])	continue;
		visited[next.first] = true;
		dfs(next.first, dist + next.second);
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B >> C;
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	visited[1] = true;
	dfs(1, 0);
	memset(visited, false, sizeof(bool) * (N + 1));

	visited[max_node] = true;
	dfs(max_node, 0);
	cout << max_dist << '\n';
}

