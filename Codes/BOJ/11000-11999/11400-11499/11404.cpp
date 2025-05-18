#include <bits/stdc++.h>

#define MIN(a, b)	a<b ? a:b
#define IDX(x)		x - 1

using namespace std;

const int INF = 999999999;
int city[101][101];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(i!=j) city[i][j] = INF;
		}
	}

	while (m--) {
		int src, dst, cost;

		cin >> src >> dst >> cost;
		city[IDX(src)][IDX(dst)] = MIN(cost, city[IDX(src)][IDX(dst)]);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				city[i][j] = MIN(city[i][k] + city[k][j], city[i][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (city[i][j] == INF) {
				cout << 0 << ' ';
				continue;
			}
			cout << city[i][j] << ' ';
		}
		cout << '\n';
	}
}