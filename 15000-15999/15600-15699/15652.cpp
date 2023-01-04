#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int visited[10];

void solve(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (cnt == 0 or arr[cnt - 1] <= i) {
			arr[cnt] = i;
			solve(cnt + 1);
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	cin >> N >> M;

	solve(0);
}