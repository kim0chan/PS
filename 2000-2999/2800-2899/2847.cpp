#include <bits/stdc++.h>
using namespace std;

int N;
int cnt;
int levels[101];

int main(void) {
	cin.sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> levels[i];
	}

	for (int i = N - 2; i >= 0; i--) {
		if (levels[i] >= levels[i + 1]) {
			cnt += levels[i] - levels[i + 1] + 1;
			levels[i] = levels[i + 1] - 1;
		}
	}

	cout << cnt << '\n';
}