#include <bits/stdc++.h>

using namespace std;

int mm[6] = { 500, 100, 50, 10, 5, 1 };

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int sum = 0;
	int n, m;
	cin >> n;
	m = 1000 - n;

	for (int i = 0; i < 6; i++) {
		sum += m / mm[i];
		m = m % mm[i];
	}

	cout << sum;
}