#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, num_people;
int city[201];
int dist[201][201];
vector<pair<int, int>> v;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		fill(dist[i], dist[i] + N + 1, INF);
		dist[i][i] = 0;
	}

	int A, B, cost;
	while (M--) {
		cin >> A >> B >> cost;
		dist[A][B] = min(dist[A][B], cost);
	}

	cin >> num_people;
	for (int p = 1; p <= num_people; p++) {
		cin >> A;
		city[p] = A;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int mx = 0;
		for (int p = 1; p <= num_people; p++) {
			mx = max(mx, dist[i][city[p]] + dist[city[p]][i]);
		}
		v.push_back({ mx, i });
	}
	sort(v.begin(), v.end());

	int mn = v[0].first;
	for (auto cur : v) {
		if (mn < cur.first)	break;
		cout << cur.second << ' ';
	}
}