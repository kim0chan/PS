#include <bits/stdc++.h>

using namespace std;

int isPrime(int x) {
	if (x == 1) { return 0; }
	else {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) { return 0; }
		}
		return 1;
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int M, N;
	cin >> M >> N;
	int sum = 0;
	int min = 999999;
	int flag = 1;

	for (int i = M; i <= N; i++) {
		if (isPrime(i)) {
			sum += i;
			if (flag) {
				min = i;
				flag = 0;
			}
		}
	}

	if (!sum) {
		cout << -1 << '\n';
	}
	else {
		cout << sum << '\n' << min << '\n';
	}
}