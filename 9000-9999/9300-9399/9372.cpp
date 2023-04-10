#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int A, B;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> A >> B;
		}
		cout << N - 1 << '\n';
	}
}