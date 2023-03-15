#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, M;
int trees[1000001];

bool solve(int k) {
	ll sum = 0;

	for (int i = 0; i < N; i++) {
		if (trees[i] > k)	sum += (trees[i] - k);
	}

	return (sum >= M);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}

	int st = 0;
	int en = 2000000000;

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