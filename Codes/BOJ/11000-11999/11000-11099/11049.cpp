#include <bits/stdc++.h>
using namespace std;

const int MX = 0x7fffffff;
int ROW[501];
int COL[501];
int DP_ROW[501][501];
int DP_COL[501][501];
int DP[501][501];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ROW[i] >> COL[i];
		DP_ROW[i][i] = ROW[i];
		DP_COL[i][i] = COL[i];
	}

	for (int d = 1; d < N; d++) {
		for (int i = 1; i + d <= N; i++) {
			int j = i + d;
			DP[i][j] = 0x7fffffff;
			for (int m = i; m < j; m++) {
				DP[i][j] = min(DP[i][j], DP[i][m] + DP[m + 1][j] + DP_ROW[i][m] * DP_COL[i][m] * DP_COL[m + 1][j]);
			}
			DP_ROW[i][j] = ROW[i];
			DP_COL[i][j] = COL[j];
		}
	}

	/*
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << DP[i][j] << ' ';
		}
		cout << '\n';
	}
	*/

	cout << DP[1][N] << '\n';

}