#include <bits/stdc++.h>

using namespace std;

int isPrime(int num) {
	if (num < 2) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	int cnt = 0;

	cin >> N;
	while (N--) {
		int input;
		cin >> input;
		if (isPrime(input)) {
			cnt++;
		}
	}
	cout << cnt;
}