#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
	if (x == 1) { return false; }
	else {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0) { return false; }
		}
		return true;
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	while (1) {
		int n;
		int a, b;
		cin >> n;
		if (!n) { break; }

		for (int i = 2; 2*i <= n; i++) {
			if (isPrime(i)) {
				if (isPrime(n - i)) {
					b = i;
					a = n - i;

					cout << n << " = " << b << " + " << a << '\n';
					break;
				}
			}
		}
	}
}