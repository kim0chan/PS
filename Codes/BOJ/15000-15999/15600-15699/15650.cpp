#include <bits/stdc++.h>
using namespace std;

int N, M;
int ans[10];
bool is_used[10];

void Solve(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (depth && ans[depth - 1] >= i) continue;
		ans[depth] = i;
		Solve(depth + 1);
	}

}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	Solve(0);
}