#include <bits/stdc++.h>
using namespace std;

int N, M, A, B;
int dp[100001];
vector<int> adj[100001];

void traversal(int cur, int pre) {
	if (pre > 0) {
		dp[cur] += dp[pre];
	}
	//cout << cur << "의 dp값이 " << dp[cur] << "이 되었어요.\n";

	for (int next : adj[cur]) {
		if (next == pre) continue;
		traversal(next, cur);
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A;
		if (A > 0) {
			adj[A].push_back(i);
			adj[i].push_back(A);
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		dp[A] += B;
	}

	traversal(1, -1);

	for (int i = 1; i <= N; i++) {
		cout << dp[i] << ' ';
	}
	cout << '\n';
}