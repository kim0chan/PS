#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
	if (x == 1) {
		return false;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;

	while(1) {
		cin >> n;
		if (!n) { break; }
		int count = 0;

		for (int i = n + 1; i <= 2 * n; i++) {
			if (isPrime(i)) { count++; }
		}
		cout << count << '\n';
	}

}