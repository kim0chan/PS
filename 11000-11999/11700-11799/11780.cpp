#include <bits/stdc++.h>
using namespace std;

int adjmat[101][101];
int nextmat[101][101];
int n, m;
int a, b, c;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (adjmat[a][b]) {
			if (adjmat[a][b] > c) {
				adjmat[a][b] = c;
				nextmat[a][b] = b;
			}
		}
		else {
			adjmat[a][b] = c;
			nextmat[a][b] = b;
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)	continue;

				if (adjmat[i][k] && adjmat[k][j]) {
					if (adjmat[i][j] == 0) {
						adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
						nextmat[i][j] = nextmat[i][k];
					}
					else {
						if (adjmat[i][k] + adjmat[k][j] < adjmat[i][j]) {
							adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
							nextmat[i][j] = nextmat[i][k];
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << adjmat[i][j] << ' ';
		}
		cout << '\n';
	}

	vector<int> solve;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!nextmat[i][j]) {
				cout << 0 << '\n';
				continue;
			}

			int dst = nextmat[i][j];
			solve.push_back(i);
			while (dst != j) {
				solve.push_back(dst);
				dst = nextmat[dst][j];
			}
			solve.push_back(dst);

			cout << solve.size() << ' ';
			for (int e : solve) cout << e << ' ';

			cout << '\n';
			solve.clear();
		}
	}
}