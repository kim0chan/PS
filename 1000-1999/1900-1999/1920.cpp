#include <bits/stdc++.h>

using namespace std;

int A[100005];

int is_in(int x, int size) {
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		int mid = (start + end) / 2;
		if (A[mid] == x) return 1;
		else if (x < A[mid]) { end = mid - 1; }
		else { start = mid + 1; }
	}
	return 0;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		if (is_in(input, N)) { cout << "1\n"; }
		else { cout << "0\n"; }
	}
}