#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int DP[1001];
int N;
int temp;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	DP[0] = arr[0];
	int solve = DP[0];
	for (int i = 1; i < N; i++) {
		temp = 0;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				temp = max(temp, DP[j]);
			}
		}
		DP[i] = temp + arr[i];
		solve = max(solve, DP[i]);
	}

	cout << solve << '\n';
}