#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	vector<bool> sieve(N + 1, true);
	sieve[1] = false;

	int solve = -1, count = 0;

	for (int i = 2; i <= N; i++) {
		if (!sieve[i]) continue;
		for (int j = i; j <= N; j += i) {
			if (!sieve[j]) continue;
			sieve[j] = false;
			count++;
			if (count == K) {
				solve = j;
				break;
			}
		}
	}

	cout << solve << '\n';
}