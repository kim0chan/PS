#include <bits/stdc++.h>

using namespace std;

int card[500004];

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N, M;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
	sort(card, card + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int comp;
		cin >> comp;

		if (binary_search(card, card + N, comp)) {
			cout << 1;
		}
		else {
			cout << 0;
		}
		cout << ' ';
	}
}