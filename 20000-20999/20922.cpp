#include <bits/stdc++.h>
using namespace std;
#define MAX(a, b) a>b ? a:b

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	vector<int> series(N);
	vector<int> check(100001);

	for (int i = 0; i < N; i++) {
		cin >> series[i];
	}

	int en = 0, solve = 0;
	check[series[en]]++;
	for (int st = 0; st < N; st++) {
		while (en + 1 != N && check[series[en + 1]] < K) {
			en++;
			check[series[en]]++;
		}
		solve = MAX(solve, (en - st + 1));
		check[series[st]]--;
	}

	cout << solve << '\n';
}