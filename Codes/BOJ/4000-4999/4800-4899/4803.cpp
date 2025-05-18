#include <bits/stdc++.h>
using namespace std;

vector<int> adj[505];
bool visited[505];
bool is_tree;
int N, M, A, B, T, trees;

void dfs(int cur, int prev) {
	for (auto next : adj[cur]) {
		if (next == prev)	continue;
		if (visited[next]) {
			is_tree = false;
			continue;
		}
		visited[next] = true;
		dfs(next, cur);
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	while (1) {
		cin >> N >> M;
		if (!N && !M)	break;
		
		fill(visited, visited + N + 1, 0);
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
		}
		trees = 0;

		while (M--) {
			cin >> A >> B;
			adj[A].push_back(B);
			adj[B].push_back(A);
		}

		for (int i = 1; i <= N; i++) {
			if (visited[i])	continue;
			visited[i] = true;
			is_tree = true;
			dfs(i, -1);
			trees += is_tree;
		}

		cout << "Case " << ++T << ": ";
		if (!trees)	cout << "No trees." << '\n';
		else if (trees == 1)	cout << "There is one tree." << '\n';
		else	cout << "A forest of " << trees << " trees." << '\n';
	}
}