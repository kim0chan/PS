#include <bits/stdc++.h>
using namespace std;

int N;

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int ans = 0;

	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	for (int i = 0; i < N; i++) {
		ans += A[i] * B[N - (i + 1)];
	}

	cout << ans << '\n';
}