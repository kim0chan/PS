#include <bits/stdc++.h>

using namespace std;

int coin[11];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, K;
	int a;
	int count = 0;

	cin >> N >> K;
	a = N;

	while (a--) {
		cin >> coin[a];
	}

	for (int i = 0; i < N; i++) {
		if (!K) { break; }
		if (K >= coin[i]) {
			count = count + K / coin[i];
			K = K % coin[i];
		}
	}

	cout << count;
}