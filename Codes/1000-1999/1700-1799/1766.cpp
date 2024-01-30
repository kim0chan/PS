#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
int indegree[32001];
vector<int> adj[32001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		adj[A].push_back(B);
		indegree[B]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (!indegree[i])	pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();	pq.pop();
		cout << cur << ' ';

		for (int next : adj[cur]) {
			indegree[next]--;
			if (!indegree[next])	pq.push(next);
		}
	}
	cout << '\n';
}