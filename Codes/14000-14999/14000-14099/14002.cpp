#include <bits/stdc++.h>
using namespace std;

int A[1001], DP[1001], path[1001];
int N;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	DP[N - 1] = 1;
	path[N - 1] = N - 1;
	for (int i = N - 2; i >= 0; i--) {
		int local_max = 0;
		int j = i + 1;

		while (j < N) {
			if (A[i] < A[j]) {
				if (local_max < DP[j]) {
					local_max = DP[j];
					path[i] = j;
				}
			}
			j++;
		}

		DP[i] = local_max + 1;
	}

	auto addr = max_element(DP, DP + N);
	cout << *addr << '\n';

	/*
	for (int i = 0; i < N; i++) {
		cout << path[i] << ' ';
	}
	*/
	
	int idx = addr - DP;
	while (DP[idx] != 1) {
		cout << A[idx] << ' ';
		idx = path[idx];
	}
	cout << A[idx] << '\n';

}