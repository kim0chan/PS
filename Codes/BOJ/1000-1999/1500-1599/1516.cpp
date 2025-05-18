#include <bits/stdc++.h>
using namespace std;

int N;
int indegree[501];
int timetobuild[501];
int ans[501];
vector<int> adj[501];
vector<int> prerequisites[501];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int pre;
		cin >> timetobuild[i];
		while (true) {
			cin >> pre;
			if (pre == -1)	break;
			adj[pre].push_back(i);
			prerequisites[i].push_back(pre);
			indegree[i]++;
		}
	}

	queue<int> qu;
	for (int i = 1; i <= N; i++) {
		if (!indegree[i]) qu.push(i);
	}

	while (!qu.empty()) {
		int cur = qu.front();	qu.pop();
		int mx = 0;

		for (int nxt : adj[cur]) {
			indegree[nxt]--;
			if (!indegree[nxt]) {
				qu.push(nxt);
			}
		}

		for (int prev : prerequisites[cur]) {
			mx = max(mx, ans[prev]);
		}
		ans[cur] = mx + timetobuild[cur];
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}
}