#include <bits/stdc++.h>

#define MIN(a, b)	a<b ? a:b
#define IDX(x)		x - 1

using namespace std;

int adj[201][201];
int route[1001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> adj[i][j];
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) { adj[i][j] = 1; }
				if (adj[i][k] && adj[k][j]) { adj[i][j] = 1; }
			}
		}
	}

	
	/*
	cout << "---------------\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << adj[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "---------------\n";
	*/
	

	for (int i = 0; i < M; i++) {
		cin >> route[i];
	}

	for (int i = 0; i < M - 1; i++) {
		if (adj[IDX(route[i])][IDX(route[i + 1])] == 0) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
}