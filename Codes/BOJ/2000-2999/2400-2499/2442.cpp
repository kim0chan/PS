#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int j = N - 1 - i;
		for (int k = 0; k < j; k++) {
			cout << ' ';
		}
		for (int k = 0; k < 1 + 2 * i; k++) {
			cout << '*';
		}
		cout << '\n';
	}
}