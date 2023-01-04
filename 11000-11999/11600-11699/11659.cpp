#include <bits/stdc++.h>

using namespace std;

int A[100004];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int input;
		cin >> input;
		A[i] = A[i - 1] + input;
	}

	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << A[b] - A[a - 1] << '\n';
	}
}