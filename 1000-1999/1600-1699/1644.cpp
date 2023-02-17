#include <bits/stdc++.h>

using namespace std;

const int MXN = 4000002;

bool isPrime(int n) {
	if (n == 1) { return 0; }
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	vector<int> primes;
	int N;
	cin >> N;

	if (N == 1) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		if (isPrime(i))	primes.push_back(i);
	}
	primes.push_back(0);
	
	int st = 0, en = 1, solve = 0, sum = primes[0];
	while (1) {
		if (sum == N) { solve++; }
		if (sum <= N) { sum += primes[en++]; }
		if (sum > N) { sum -= primes[st++]; }
		if (en == primes.size()) { break; }
	}

	cout << solve << '\n';
}