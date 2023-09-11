#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[10];
int ans[10];
bool visited[10];

void Solve(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i])	continue;
		ans[depth] = num[i];
		visited[i] = true;
		Solve(depth + 1);
		visited[i] = false;
	}
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);

	Solve(0);
}