#include <bits/stdc++.h>

#define MIN(a, b) a<b ? a:b
using namespace std;

int arr[100001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int min = 2000000001;

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		int idx = lower_bound(arr, arr + N, arr[i] + M) - arr;
		if (idx >= N) { continue; }
		min = MIN(min, arr[idx] - arr[i]);
	}

	cout << min << '\n';
}