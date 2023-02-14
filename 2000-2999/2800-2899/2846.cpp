#include <bits/stdc++.h>

#define MAX(a, b)	a>b ? a:b
using namespace std;

int arr[1001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	int solve = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int cur = arr[0];
	int local = 0;

	for (int i = 1; i < N; i++) {
		if (cur < arr[i]) {
			local += (arr[i] - cur);
			solve = MAX(solve, local);
			cur = arr[i];
		}
		else {
			local = 0;
			cur = arr[i];
		}
	}

	cout << solve << '\n';
}