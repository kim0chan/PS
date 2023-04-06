#include <bits/stdc++.h>
using namespace std;

int cost[101][101];
int dp[101][101];
int indegree[101];
int N, M, A, B, C;
vector<int> adj[101];
vector<int> basics;

void dpSetup(int k) {
	for (int i = 1; i <= k; i++) {
		dp[i][i] = 1;
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	dpSetup(N);
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		adj[B].push_back(A);
		indegree[A]++;
		cost[A][B] = C;
	}

	queue<int> qu;
	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) {
			qu.push(i);
			basics.push_back(i);
		}
	}

	while (!qu.empty()) {
		int cur = qu.front();	qu.pop();
		for (int next : adj[cur]) {
			for (int e : basics)	dp[next][e] += (dp[cur][e] * cost[next][cur]);
			indegree[next]--;
			if (!indegree[next])	qu.push(next);
		}
	}

	for (int e : basics) {
		cout << e << ' ' << dp[N][e] << '\n';
	}
}
