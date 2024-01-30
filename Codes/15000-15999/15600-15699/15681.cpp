#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool visited[100001];
int p[100001];
int subTreeSize[100001];
int N, R, Q, A, B, query;

int Count(int cur) {
	visited[cur] = true;
	
	for (int next : adj[cur]) {
		if (visited[next])	continue;
		subTreeSize[cur] += Count(next);
	}
	subTreeSize[cur]++;
	return subTreeSize[cur];
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> R >> Q;
	while (--N) {
		cin >> A >> B;
		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	Count(R);
	while (Q--) {
		cin >> query;
		cout << subTreeSize[query] << '\n';
	}
}