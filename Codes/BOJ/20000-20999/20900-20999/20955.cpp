#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
int solve = -1;
vector<int> adj[100001];
bool visited[100001];

void traverse(int cur, int pre) {
	visited[cur] = true;

	for (int next : adj[cur]) {
		if (next == pre || visited[next])	continue;
		visited[next] = true;
		traverse(next, cur);
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i])	continue;
		//cout << i << "번 노드가 연결되어 있지 않습니다.\n";
		solve++;
		traverse(i, -1);
	}

	cout << (solve) + (M + solve) - (N - 1) << '\n';
}