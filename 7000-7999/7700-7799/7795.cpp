#include <bits/stdc++.h>
using namespace std;

int A[20001];
int B[20001];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int solve = 0;
		int N, M;
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}

		sort(A, A + N);
		sort(B, B + M);

		for (int i = 0; i < N; i++) {
			int idx = M - 1;
			while (idx >= 0 && B[idx] >= A[i]) {
				idx--;
			}
			solve += (idx + 1);
		}
		cout << solve << '\n';
	}
}