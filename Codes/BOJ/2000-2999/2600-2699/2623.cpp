#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
int indegree[1001];
vector<int> adj[1001];
vector<int> solve;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int iter;
		cin >> iter;
		if (!iter)	continue;
		cin >> A;
		for (int j = 0; j < iter - 1; j++) {
			cin >> B;
			adj[A].push_back(B);
			indegree[B]++;

			swap(A, B);
		}
	}

	queue<int> qu;
	for (int i = 1; i <= N; i++) {
		if (!indegree[i])	qu.push(i);
	}

	while (!qu.empty()) {
		int cur = qu.front();	qu.pop();
		solve.push_back(cur);

		for (int next : adj[cur]) {
			indegree[next]--;
			if (!indegree[next])	qu.push(next);
		}
	}

	if (solve.size() != N) cout << "0\n";
	else {
		for (int e : solve) {
			cout << e << '\n';
		}
	}
}