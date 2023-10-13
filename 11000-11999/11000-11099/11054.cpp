#include <bits/stdc++.h>
using namespace std;

int A[1001];
int DP[1001][2];
int N;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	DP[N - 1][1] = 1;
	DP[0][0] = 1;

	for (int i = N - 2; i >= 0; i--) {
		int local_max = 0;
		for (int j = i + 1; j < N; j++) {
			if (A[i] > A[j]) {
				local_max = max(local_max, DP[j][1]);
			}
		}
		DP[i][1] = local_max + 1;
	}

	for (int i = 1; i < N; i++) {
		int local_max = 0;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				local_max = max(local_max, DP[j][0]);
			}
		}
		DP[i][0] = local_max + 1;
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer = max(answer, DP[i][0] + DP[i][1]);
	}

	cout << answer - 1 << '\n';
}