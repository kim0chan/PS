#include <bits/stdc++.h>
using namespace std;

int parent[500001];
int node_rank[500001];

int Find(int x) {
	if (parent[x] == x)	return x;
	return parent[x] = Find(parent[x]);
}

bool TestAndUnion(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x == y) {
		return true;
	}

	if (node_rank[x] < node_rank[y])		parent[x] = y;
	else if (node_rank[x] > node_rank[y])	parent[y] = x;
	else {
		parent[x] = y;
		node_rank[x]++;
	}
	return false;
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		node_rank[i] = 1;
	}
	
	for (int step = 1; step <= m; step++) {
		int a, b;
		cin >> a >> b;
		if (TestAndUnion(a, b)) {
			ans = step;
			break;
		}
	}

	cout << ans << '\n';
}