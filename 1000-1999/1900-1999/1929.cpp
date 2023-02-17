#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	vector<bool> sieve(M + 1, true);
	sieve[1] = false;
	for (int i = 2; i * i <= M; i++) {
		if (!sieve[i]) continue;
		for (int j = i * i; j <= M; j += i) {
			sieve[j] = false;
		}
	}

	for (int i = N; i <= M; i++) {
		if (sieve[i]) cout << i << '\n';
	}
}