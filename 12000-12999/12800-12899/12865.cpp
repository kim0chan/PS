#include <bits/stdc++.h>
#define W	first
#define V	second
#define IDX(x)	x-1
#define MAX(a, b)	a>b ? a:b

using namespace std;

int solve[101][100001];
pair<int, int> thing[101];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> thing[i].W >> thing[i].V;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (thing[i].W <= j) {
				solve[i][j] = MAX(solve[i-1][j], thing[i].V+solve[i-1][j-thing[i].W]);
			}
			else {
				solve[i][j] = solve[i - 1][j];
			}
		}
	}

	/*	DEBUGGING CODE
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			cout << solve[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	cout << solve[N][K] << '\n';
}