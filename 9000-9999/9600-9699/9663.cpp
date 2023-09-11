#include <bits/stdc++.h>
using namespace std;

bool is_used_1[40];
bool is_used_2[40];
bool is_used_3[40];
int cnt = 0;
int N;

void Solve(int cur) {
	if (cur == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (is_used_1[i] || is_used_2[i + cur] || is_used_3[cur - i + N - 1])	continue;
		is_used_1[i] = is_used_2[i + cur] = is_used_3[cur - i + N - 1] = true;
		Solve(cur + 1);
		is_used_1[i] = is_used_2[i + cur] = is_used_3[cur - i + N - 1] = false;
	}
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	Solve(0);
	cout << cnt << '\n';
}