#include <bits/stdc++.h>

using namespace std;

int fibo[100];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int n;
	cin >> n;

	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	cout << fibo[n] << '\n';
}