#include <bits/stdc++.h>
using namespace std;

int M, N;
int cnt;
int arr[101][10001];

void compress(int arr[]) {
	vector<int> v(arr, arr + N);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < N; i++) {
		arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
	}
}

bool compare(int a[], int b[]) {
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
		compress(arr[i]);
	}

	for (int i = 0; i < M - 1; i++) {
		for (int j = i + 1; j < M; j++) {
			cnt += compare(arr[i], arr[j]);
		}
	}
	cout << cnt << '\n';
}