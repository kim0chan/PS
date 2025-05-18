#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
vector<int> adj[501];
int visited[501];
int solve;

void BFS() {
	queue<int> qu;
	qu.push(1);
	visited[1] = 1;

	while (!qu.empty()) {
		int cur = qu.front();	qu.pop();
		solve++;

		if (visited[cur] > 2)	continue;
		for (auto next : adj[cur]) {
			if (visited[next])	continue;
			qu.push(next);
			visited[next] = visited[cur] + 1;
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	while (M--) {
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	BFS();
	cout << solve - 1 << '\n';
}