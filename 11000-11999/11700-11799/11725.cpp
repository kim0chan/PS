#include <bits/stdc++.h>
using namespace std;

int N, A, B;
int p[100001];
vector<int> adj[100001];

void dfs(int V) {
	for (auto next : adj[V]) {
		if (next == p[V])	continue;
		p[next] = V;
		dfs(next);
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	
	dfs(1);
	for (int i = 2; i <= N; i++)	cout << p[i] << '\n';
}