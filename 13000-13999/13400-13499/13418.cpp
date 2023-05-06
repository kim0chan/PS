#include <bits/stdc++.h>
#define COST	first
#define DST		second
using namespace std;

int N, M, A, B, C;
int cnt, best, worst;
vector<pair<int, int>> adj[1004];
bool chk[1004];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i <= M; i++) {
		cin >> A >> B >> C;
		adj[A].push_back({ C, B });
		adj[B].push_back({ C, A });
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq_worst;
	priority_queue<tuple<int, int, int>> pq_best;
	chk[0] = true;
	for (auto next : adj[0]) {
		pq_best.push({ next.COST, 0, next.DST });
	}

	//cout << "최적 루트입니다.\n";
	while (cnt < N) {
		int c, a, b;
		tie(c, a, b) = pq_best.top();	pq_best.pop();
		if (chk[b])	continue;
		//cout << a << "와 " << b << " 사이의 간선입니다.";
		if (!c) {
			best++;
			//cout << "이것은 오르막길입니다...";
		}
		//cout << '\n';
		cnt++;
		chk[b] = true;
		
		for (auto next : adj[b]) {
			if (chk[next.DST])	continue;
			pq_best.push({ next.COST, b, next.DST });
		}
	}

	//cout << best << '\n';
	memset(chk, 0, sizeof(chk));
	cnt = 0;

	chk[0] = true;
	for (auto next : adj[0]) {
		pq_worst.push({ next.COST, 0, next.DST });
	}
	//cout << "최악 루트입니다.\n";

	while (cnt < N) {
		int c, a, b;
		tie(c, a, b) = pq_worst.top();	pq_worst.pop();
		if (chk[b])	continue;
		//cout << a << "와 " << b << " 사이의 간선입니다.";
		if (!c) {
			worst++;
			//cout << "이것은 오르막길입니다...";
		}
		//cout << '\n';
		cnt++;
		chk[b] = true;

		for (auto next : adj[b]) {
			if (chk[next.DST])	continue;
			pq_worst.push({ next.COST, b, next.DST });
		}
	}

	//cout << worst << '\n';
	long long ans = (worst * worst) - (best * best);
	cout << ans << '\n';
}