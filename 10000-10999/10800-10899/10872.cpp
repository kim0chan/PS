#include <bits/stdc++.h>

using namespace std;

int fact(int N) {
	if (N == 0) return 1;
	return N * fact(N - 1);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;
	cout << fact(N);
}