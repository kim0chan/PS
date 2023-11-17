#include <bits/stdc++.h>
using namespace std;

int N, M;
int parent[1000001];
int node_rank[1000001];

int Find(int x) {
	if (x == parent[x])	return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		if (node_rank[x] < node_rank[y])	parent[x] = y;
		else if (node_rank[x] > node_rank[y]) parent[y] = x;
		else {
			parent[x] = y;
			node_rank[x]++;
		}
	}
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		parent[i] = i;
		node_rank[i] = 1;
	}

	while (M--) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd) {
			if (Find(a) == Find(b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			Union(a, b);
		}
	}
}