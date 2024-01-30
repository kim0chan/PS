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

void printGoldBach(int x) {
	int a, b;

	for (int i = 2; i <= x / 2; i++) {
		if (isPrime(i)) {
			if (isPrime(x - i)) {
				a = i;
				b = x - i;
			}
		}
	}
	cout << a << ' ' << b << '\n';
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		printGoldBach(n);
	}
}