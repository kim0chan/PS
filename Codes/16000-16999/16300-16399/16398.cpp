#include <bits/stdc++.h>
#define COST	first
#define DST		second
using namespace std;

int N, C;
int cnt; 
long long solve;
vector<pair<int, int>> adj[1001];
bool check[1001];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> C;
			//if (i == j)	continue;
			adj[i].push_back({ C, j });
			adj[j].push_back({ C, i });
		}
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	check[0] = true;
	for (auto next : adj[0]) {
		pq.push({ next.COST, 0, next.DST });
	}

	while (cnt < N - 1) {
		int c, a, b;
		tie(c, a, b) = pq.top();	pq.pop();
		if (check[b])	continue;
		cnt++;
		solve += (long long)c;
		check[b] = true;
		for (auto next : adj[b]) {
			if (check[next.DST])  continue;
			pq.push({ next.COST, b, next.DST });
		}
	}

	cout << solve << '\n';
}