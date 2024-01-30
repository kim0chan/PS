#include <bits/stdc++.h>

#define MIN(a, b)	a<b ? a:b

using namespace std;

int adjmatrix[100][100];
const int INF = 50000;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);


	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adjmatrix[i][j];
			if (adjmatrix[i][j] == 0) { adjmatrix[i][j] = INF; }
		}
	}


	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				adjmatrix[i][j] = MIN(adjmatrix[i][j], adjmatrix[i][k] + adjmatrix[k][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (adjmatrix[i][j] < INF) { cout << 1 << ' '; }
			else { cout << 0 << ' '; }
		}
		cout << '\n';
	}

}