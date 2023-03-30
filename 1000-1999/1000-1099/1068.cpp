#include <bits/stdc++.h>
using namespace std;

int N, M, root;
int p[51], numLeafNodes[51];
vector<int> adj[51];

int countLeafNodes(int cur, int X) {
	if (cur == X) return 0;

	for (auto next : adj[cur]) {
		if (next == p[cur])	continue;
		numLeafNodes[cur] += countLeafNodes(next, X);
	}

	if (numLeafNodes[cur] == 0) {
		numLeafNodes[cur]++;
	}
	
	return numLeafNodes[cur];
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
		if (p[i] == -1) root = i;
		adj[i].push_back(p[i]);
		adj[p[i]].push_back(i);
	}

	cin >> M;
	cout << countLeafNodes(root, M) << '\n';
}