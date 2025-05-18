#include <bits/stdc++.h>
using namespace std;

int n, m, r, solve;
int item[101];
int adjmat[101][101];
int dropzone[101];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)	cin >> item[i];
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		adjmat[a][b] = l;
		adjmat[b][a] = l;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j)	continue;
				if (adjmat[i][k] && adjmat[k][j]) {
					if (adjmat[i][j] == 0)	adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
					else {
						adjmat[i][j] = min(adjmat[i][j], adjmat[i][k] + adjmat[k][j]);
					}
				}
			}
		}
	}

	/*
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << adjmat[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((adjmat[i][j] && adjmat[i][j] <= m) || i == j) {
				//cout << i << "에서 " << j << " 갈 수 있어서 " << item[j] << "이 더해졌어요. (" << adjmat[i][j] << ")\n";
				dropzone[i] += item[j];
			}
		}
		//cout << i << "에서 아이템을 " << dropzone[i] << "이나 먹을 수 있네요.\n";
		solve = max(solve, dropzone[i]);
	}

	cout << solve << '\n';
}