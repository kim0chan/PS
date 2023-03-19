#include <bits/stdc++.h>
using namespace std;

int S[1000001];
int N, K;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)	cin >> S[i];

	int en = 0, erase = 0, solve = 0;
	while (S[en] % 2 && en < N)	en++;
	for (int st = en; st < N; st++) {
		while (en < N - 1 && erase + S[en + 1] % 2 <= K) {
			en++;
			erase += S[en] % 2;
		}

		solve = max(solve, en - st - erase + 1);
		erase -= S[st] % 2;
	}

	cout << solve << '\n';
}