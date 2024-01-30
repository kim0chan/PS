#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	int ans = 0;

	while (N >= 0) {
		if (N % 5 == 0) {
			ans += N / 5;
			cout << ans << '\n';
			return 0;
		}

		N -= 3;
		ans++;
	}

	cout << -1 << '\n';
}