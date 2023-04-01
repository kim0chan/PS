#include <bits/stdc++.h>
using namespace std;

int N, A, B, C;
int max_node, max_dist;
bool visited[100001];
vector<pair<int, int>> adj[100001];

void dfs(int cur, int dist) {
	visited[cur] = true;
	if (dist > max_dist) {
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
	for (int i = 1; i <= N; i++) {
		cin >> A;
		while (1) {
			cin >> B;
			if (B == -1)	break;
			cin >> C;
			adj[A].push_back({ B, C });
			adj[B].push_back({ A, C });
		}
	}

	dfs(1, 0);
	memset(visited, false, sizeof(bool) * (N + 1));
	dfs(max_node, 0);
	cout << max_dist << '\n';
}