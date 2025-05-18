#include <bits/stdc++.h>
#define NODE	first
#define DIST	second
using namespace std;

int N, M, A, B, D;
vector<pair<int, int>> adj[1001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for(int i = 0; i < N - 1; i++) {
		cin >> A >> B >> D;
		adj[A].push_back({ B, D });
		adj[B].push_back({ A, D });
	}

	while (M--) {
		cin >> A >> B;
		queue<pair<int, int>> qu;
		vector<bool> visited(N + 1);
		visited[A] = true;
		qu.push({ A, 0 });

		while (!qu.empty()) {
			pair<int, int> cur = qu.front(); qu.pop();
			if (cur.NODE == B) {
				cout << cur.DIST << '\n';
				break;
			}

			for (auto next : adj[cur.NODE]) {
				if (visited[next.NODE])	continue;
				visited[next.NODE] = true;
				qu.push({ next.NODE, next.DIST + cur.DIST });
			}
		}
	}
}