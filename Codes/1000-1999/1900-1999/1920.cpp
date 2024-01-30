#include <bits/stdc++.h>
using namespace std;

int A[100001];
int N, M;

int binarysearch(int tar9et) {
	int st = 0, en = N - 1;
	while (st <= en) {
		int mid = (st + en) / 2;

		if (A[mid] < tar9et)	st = mid + 1;
		else if (A[mid] > tar9et)en = mid - 1;
		else return 1;
	}

	return 0;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	cin >> M;
	while (M--) {
		int tar9et;
		cin >> tar9et;
		cout << binarysearch(tar9et) << '\n';
	}
}