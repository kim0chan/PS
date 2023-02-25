#include <bits/stdc++.h>
using namespace std;

#define MAX(a, b)	a>b ? a:b

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, d, k, c;
	cin >> N >> d >> k >> c;

	vector<int> sushi(N + k);
	vector<int> check(d + 1);

	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}
	for (int i = 0; i < k; i++) {
		sushi[N + i] = sushi[i];
	}
	
	int en = 0, local = 0, solve = 0;

	for (int st = 0; st < N + k; st++) {
		while (en < N + k && en - st < k) {
			if (check[sushi[en]] == 0)	local++;
			check[sushi[en]]++;
			en++;
		}
		if (en == N + k)	break;
		//cout << "(st, en) = (" << st << ", " << en << ")\n";

		if (check[c] == 0) {
			solve = max(solve, local + 1);
		}
		else {
			solve = max(solve, local);
		}
		
		//cout << "solve: " << solve << '\n';
		if (check[sushi[st]] == 1)	local--;
		check[sushi[st]]--;
	}
	cout << solve << '\n';
}