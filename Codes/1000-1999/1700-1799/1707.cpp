#include <bits/stdc++.h>
using namespace std;

int K, V, E;
vector<int> adj[20001];
int tp[20001];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	while (K--) {
		bool isBipartite = true;
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (tp[i])	continue;
			queue<int> qu;
			qu.push(i);
			tp[i] = 1;
			while (!qu.empty()) {
				int cur = qu.front();	qu.pop();
				for (int nxt : adj[cur]) {
					if (tp[nxt]) continue;
					qu.push(nxt);
					tp[nxt] = tp[cur] * -1;
				}
			}
		}

		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < (int)adj[i].size(); j++) {
				if (tp[i] == tp[adj[i][j]]) {
					isBipartite = false;
					break;
				}
			}
			if (!isBipartite)	break;
		}

		if (!isBipartite) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}

		for (int i = 1; i <= V; i++) {
			adj[i].clear();
		}
		fill(tp, tp + V + 1, 0);
	}
}