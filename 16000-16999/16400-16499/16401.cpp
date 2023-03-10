#include <bits/stdc++.h>
using namespace std;

int M, N;
int snacks[1000001];

bool solve(int x) {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += snacks[i] / x;
	}

	return sum >= M;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> snacks[i];
	}

	int st = 0;
	int en = 1000000000;

	while (st < en) {
		int mid = (st + en + 1) / 2;
		if (solve(mid)) {
			st = mid;
		}
		else {
			en = mid - 1;
		}
	}

	cout << st << '\n';
}