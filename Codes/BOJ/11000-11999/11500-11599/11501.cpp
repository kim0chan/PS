#include <bits/stdc++.h>
using namespace std;

int arr[1000001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		long long solve = 0;
		long long profit = 0;
		long long maxi = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (maxi < arr[i]) {
				solve += profit;
				profit = 0;
				maxi = arr[i];
			}
			else {
				profit += (maxi - arr[i]);
			}
		}
		solve += profit;

		cout << solve << '\n';
	}
}