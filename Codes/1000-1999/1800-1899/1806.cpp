#include <bits/stdc++.h>

#define MIN(a, b)	a<b ? a:b
using namespace std;

const int INF = 0x7fffffff;
int arr[100001];
int solve = INF;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int en = 0;
	int sum = arr[0];

	for (int st = 0; st < N; st++) {
		while (en < N && sum < S) {
			en++;
			if (en != N) { sum += arr[en]; }
		}
		if (en == N) { break; }
		solve = MIN(solve, en - st + 1);
		sum -= arr[st];
	}
	if (solve == INF) { solve = 0; }
	cout << solve << '\n';

}