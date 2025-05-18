#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
int N, M, V;

void DFS(int V) {
	stack<int> st;
	st.push(V);
	
	while (!st.empty()) {
		int cur = st.top();	st.pop();
		if (visited[cur])	continue;
		visited[cur] = true;
		cout << cur << ' ';
		for (int i = 0; i < (int)adj[cur].size(); i++) {
			int next = adj[cur][adj[cur].size() - 1 - i];
			if (visited[next])	continue;
			st.push(next);
		}
	}
	cout << '\n';
}

void DFS_R(int v) {
	visited[v] = true;
	cout << v << ' ';
	for (auto next : adj[v]) {
		if (visited[next])	continue;
		DFS_R(next);
	}
}

void BFS(int V) {
	queue<int> qu;
	visited[V] = true;
	qu.push(V);

	while (!qu.empty()) {
		int cur = qu.front();	qu.pop();
		cout << cur << ' ';
		for (auto next : adj[cur]) {
			if (visited[next])	continue;
			visited[next] = true;
			qu.push(next);
		}
	}
	cout << '\n';
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M >> V;
	while (M--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)	sort(adj[i].begin(), adj[i].end());

	DFS_R(V);
	cout << '\n';
	fill(visited + 1, visited + N + 1, false);
	BFS(V);
}