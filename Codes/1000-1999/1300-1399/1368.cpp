#include <bits/stdc++.h>
using namespace std;

#define X	first
#define Y	second

int N, cost;
vector<pair<int, int>> adj[302];
bool check[302];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> cost;
		adj[i].push_back({ cost, 301 });
		adj[301].push_back({ cost, i });
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cost;
			if (cost) {
				adj[i].push_back({ cost, j });
				adj[j].push_back({ cost, i });
			}
		}
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	int cnt = 0;
	int ans = 0;
	check[1] = true;

	for (pair<int, int> next : adj[1]) {
		pq.push({ next.X, 1, next.Y });
	}
	while (cnt < N) {
		int c, a, b;
		tie(c, a, b) = pq.top();	pq.pop();
		if (check[b])	continue;
		check[b] = true;
		ans += c;
		cnt++;
		
		for (pair<int, int> next : adj[b]) {
			if (!check[next.Y]) {
				pq.push({ next.X, b, next.Y });
			}
		}
	}

	cout << ans << '\n';
}
