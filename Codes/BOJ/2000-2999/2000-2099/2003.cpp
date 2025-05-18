#include <bits/stdc++.h>
using namespace std;

int A[10001];
int N, M;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int st = 0, en = 1, solve = 0, sum = A[0];
	while (1) {
		if (sum == M)	solve++;
		if (en == N)	break;
		if (sum <= M)	sum += A[en++];
		if (sum > M)	sum -= A[st++];
	}

	cout << solve << '\n';
}