#include <bits/stdc++.h>
using namespace std;

int A[1001], DP[1001];
int N;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	DP[N - 1] = 1;
	
	for (int i = N - 2; i >= 0; i--) {
		int local_max = 0;
		int j = i + 1;
		while (j < N) {
			if (A[j] > A[i])	local_max = max(local_max, DP[j]);
			j++;
		}
		DP[i] = local_max + 1;
	}

	cout << *max_element(DP, DP + N) << '\n';
}