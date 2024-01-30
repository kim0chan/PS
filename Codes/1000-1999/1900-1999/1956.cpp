#include <bits/stdc++.h>

#define IDX(x)		x - 1
#define MIN(a, b)	a<b?a:b

using namespace std;

long long int adjmat[401][401];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adjmat[IDX(a)][IDX(b)] = c;
	}

	for (int k = 0; k < V; k++) {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (adjmat[i][k] && adjmat[k][j]) {
					if (adjmat[i][j] == 0) { adjmat[i][j] = adjmat[i][k] + adjmat[k][j]; continue; }
					adjmat[i][j] = MIN(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
				}
			}
		}
	}

	int found = 0;
	int ans = 100000000;
	for (int i = 0; i < V; i++) {
		if (adjmat[i][i]) {
			ans = MIN(ans, adjmat[i][i]);
			found = 1;
		}
	}

	if (found) {
		cout << ans << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}