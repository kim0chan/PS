#include <bits/stdc++.h>
using namespace std;

int N, M, A, B, check;
vector<int> adj[32001];
int indegree[32001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		adj[A].push_back(B);
		indegree[B]++;
	}

	queue<int> qu;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) qu.push(i);
	}

	while (!qu.empty()) {
		int cur = qu.front();	qu.pop();
		cout << cur << ' ';
		check++;

		for (int next : adj[cur]) {
			indegree[next]--;
			if (indegree[next] == 0)	qu.push(next);
		}
	}

	//cout << "check: " << check << ", N: " << N << '\n';
	//cout << "solve size: " << (int)solve.size() << '\n';

	cout << '\n';
}