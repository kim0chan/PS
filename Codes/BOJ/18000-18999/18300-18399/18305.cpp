#include <bits/stdc++.h>
#define ll	long long
using namespace std;

const ll MX = 0x7fffffffffffffff;
ll DP[501][501];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	vector<ll> lengths(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> lengths[i];
		lengths[i] += lengths[i - 1];
	}	// lengths[b] - lengths[a - 1]은 a~b 길이 반환

	for (int len = 2; len <= N; len++) {
		for (int i = 1; i <= N - len + 1; i++) {
			int j = i + len - 1;
			DP[i][j] = MX;

			for (int k = i; k < j; k++) {
				DP[i][j] = min(DP[i][j], lengths[k] - lengths[i - 1] + lengths[j] - lengths[k] + DP[i][k] + DP[k + 1][j]);
			}
		}
	}

	/*
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << DP[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "=============\n";
	*/

	cout << DP[1][N] << '\n';
}