#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		int a = 1;

		for (int i = 0; i < N; i++) {
			a = a * (M - i);
			a = a / (1 + i);
		}
		cout << a << '\n';
	}
}