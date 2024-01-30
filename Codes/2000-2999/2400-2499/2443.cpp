#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		cout << '*';
		for (int j = 1; j < N - i; j++) {
			cout << "**";
		}
		cout << '\n';
	}
}