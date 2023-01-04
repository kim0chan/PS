#include <bits/stdc++.h>
using namespace std;

int N;
int max_n = 0;
int egg_d[10];
int egg_w[10];

void solve(int k) {
	if (k == N) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (egg_d[i] <= 0) count++;
		}
		max_n = (max_n > count) ? max_n : count;
		return;
	}
	else if (egg_d[k] <= 0) {
		solve(k + 1);
	}
	else {
		int found = 0;
		for (int i = 0; i < N; i++) {
			if (i == k) continue;
			if (egg_d[i] <= 0) continue;

			found = 1;
			egg_d[k] -= egg_w[i];
			egg_d[i] -= egg_w[k];
			solve(k + 1);
			egg_d[k] += egg_w[i];
			egg_d[i] += egg_w[k];
		}
		if (!found) solve(N);
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> egg_d[i] >> egg_w[i];
	}

	solve(0);
	cout << max_n << '\n';
}